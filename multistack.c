#include<stdio.h>
#define MAX 20
#define MAXMEMORY 20
void display();
void push(int stkid,int v);
int pop(int stkid);
int stkempty(int stkid);
int stkfull(int stkid);
int stack[MAXMEMORY];
int top[MAX];
int boun[MAX];
int n=0;
main()
{
	int i, ch= 0, stkid, v=0; char chh=' ';
	printf("Enter the number of stacks u wish to create:");
	scanf("%d",&n);
	//top[0]=boun[0]=0;
	for(i=0;i<n;i++)
	{
		top[i]=boun[i]=((MAXMEMORY/n)*i);
	}
	boun[n]=MAXMEMORY;
	do
	{
		printf("***MAIN MENU***");
		printf("\n 1.Push an element in stack:");
		printf("\n 2.Pop an element from stack:");
		
		printf("\n 3. Display the elements of stack:");
	    printf("\n Enter your choice:");
	    scanf("%d",&ch);
	    printf("\n Stack number:");
		scanf("%d",&stkid);	 
	      
		switch(ch)
	    {
	    	case 1: printf("Enter the element to be added:");
	    	        scanf("%d",&v);
	    			push(stkid,v);
	    			break;
	    	case 2:	v=pop(stkid);
					printf("The element popped is: %d",v);
					break;
			case 3:	display();
					break;
	        default:printf("Sorry.Invalid choice");
			 	
		}
		printf("Do you want to continue: press 'y'||'Y' to continue:");
		fflush(stdin);
		scanf("%c",&chh);
	}
	while(chh=='y'||chh=='Y');
}
void push(int stkid,int v)
{
	if(!stkfull(stkid))//stkfull[id-1]==0
	{
	 stack[top[stkid]++]=v;
	}
}
int stkfull(int stkid)
{
	if( top[stkid]==boun[stkid+1])
		return 1;
	else
		return 0;
}
int stkempty(int stkid)
{
	if(top[stkid]==boun[stkid])
		return 1;
	else
		return 0;
}
int pop(int stkid)
{    int v;
     if(!stkempty(stkid))
	 {
      v= stack[--top[stkid]];
      return v;
	}
	 else
	 return -1;
}
void display()
{   int u;int j=0;
	for(u=0;u<n;u++)
	{    
		 printf("\n Output for stack %d :", u+1);
		 if(!stkempty(u))
		 {	 
		 for(j=top[u]-1;j>=boun[u];j--)
		 {
		 	printf("%d",stack[j]);
		 }
	    }
	else
	{
		printf("empty stack");
	}
	}
}
	



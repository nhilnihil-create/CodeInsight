#include<stdio.h>

int main()
{
	int x,y,d;
	while(scanf("%d %d",&x,&y))
	{
		if(x==0)
		{
			return 0;
		}
		else if(x==1||x==2)
		{
			d=(2003+2003/4-2003/100+2003/400+(13*(x+12)+8)/5+y)%7;
		}
		else if(x>=13)
		{
			d=7;
		}
		else
		{
			d=(2004+2004/4-2004/100+2004/400+(13*x+8)/5+y)%7;
		}

		if(d==0)
		{
			printf("Sunday\n");
		}
		else if(d==1)
		{
			printf("Monday\n");
		}
		else if(d==2)
		{
			printf("Tuesday\n");
		}
		else if(d==3)
		{
			printf("Wednesday\n");
		}
		else if(d==4)
		{
			printf("Thursday\n");
		}
		else if(d==5)
		{
			printf("Friday\n");
		}
		else if(d==6)
		{
			printf("Saturday\n");
		}
		else if(d==7)
		{
		}
	}
}
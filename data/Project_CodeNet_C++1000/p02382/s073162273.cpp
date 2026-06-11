#include<stdio.h>
#include<math.h>
int main()
{
	int x[100]={0},y[100]={0};
	int n;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	} 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&y[i]);
	}
	double dis1=0,dis2=0,dis3=0;
	double sum=0.000000,sum1=0.000000;
	for(int i=0;i<n;i++)
	{
		dis1=dis1+fabs(x[i]-y[i]);
		sum=sum+pow(fabs(x[i]-y[i]),2);
		dis2=sqrt(sum);
		sum1=sum1+pow(fabs(x[i]-y[i]),3);
		dis3=pow(sum1,1.0/3.0);
	}	
	double max=0;
	double abs[100];
	for(int i=0;i<n;i++)
	{
		abs[i]=fabs(x[i]-y[i]);
		if(abs[i]>max){max=abs[i];}
	}
	printf("%lf\n",dis1);
	printf("%lf\n",dis2);
	printf("%lf\n",dis3);
	printf("%lf\n",max);
}
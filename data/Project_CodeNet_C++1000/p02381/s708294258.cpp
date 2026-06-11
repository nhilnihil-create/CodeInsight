#include<stdio.h>
#include<math.h>
int main()
{
	int n,a[1000];
	double average;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		int sum=0;
		for(int i=0;i<n;i++)
		  {
		  	 scanf("%d",&a[i]);
	        sum=sum+a[i];
			average=1.0*sum/n;
		  }
		  
		  double sum2=0.0;
	 for(int i=0;i<n;i++)
	  {
	  	sum2=sum2+(average-a[i])*(average-a[i]);
	  }
	  printf("%lf\n",sqrt(sum2/n));
	}
	
}
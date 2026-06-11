#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstdlib>
using namespace std;

int main()
{
	int i;
    double n,x[1001],y[1001],sum,d,p,max=0;
	
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x[i];
	}
	for(i=0;i<n;i++){
		cin>>y[i];
	}
	for(p=1;p<4;p++){
		for(i=0,sum=0;i<n;i++){
			sum+=pow(fabs(x[i]-y[i]),p);
			if(max < fabs(x[i] - y[i])) max = fabs(x[i] - y[i]);
		}
		d=pow(sum,1.0/p);
		printf("%10f\n",d);
	}
	printf("%10f\n",max);
    return 0;
}
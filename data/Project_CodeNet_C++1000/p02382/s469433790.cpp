#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main() {
	int n=0;
	int a[1005],b[1005];
	int c[1005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		c[i]=abs(a[i]-b[i]);
	}
	double sum1=0,sum2=0,sum3=0,max=0;
	for(int i=0;i<n;i++){
		sum1+=c[i];
		sum2+=c[i]*c[i];
		sum3+=c[i]*c[i]*c[i];
		if(max<c[i]){
			max=c[i];
		}
	}
	cout.precision(6);

	printf("%lf\n%lf\n%lf\n%lf\n",sum1,pow(sum2,0.5),pow(sum3,1.0/3),max);
	return 0;
}
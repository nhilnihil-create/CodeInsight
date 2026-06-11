#include <iostream>
#include <cstdio>
#include <cmath> 
using namespace std;

int main()
{
	int i;
    double n,s[1001],sum,ave,a;
	while(1){
		cin>>n;
		if(n==0)break;
		for(i=0,sum=0;i<n;i++){
			cin>>s[i];
			sum+=s[i];
		}
		ave=sum/n;
		for(i=0,sum=0;i<n;i++){
			sum+=pow(s[i]-ave,2.0);
		}
		a=sqrt(sum/n);
		printf("%10f\n",a);
	}
	
    return 0;
}
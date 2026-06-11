#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int n,s[1001];
	while(1){
		double a=0;
		cin>>n;
		if(n==0)break;
		for(int i=0;i<n;i++){
			cin>>s[i];
			a+=s[i];
		}
		double b=a/n;
		double c=0;
		for(int i=0;i<n;i++){
			c+=pow(b-s[i],2.0);
		}
		double d=0;
		d=sqrt(c/n);
		printf("%.8f\n",d);
	}
	return 0;
}
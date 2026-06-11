#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main(){
	int n,s[1000];
	double a,m,D;
	while(true){
		cin >> n;
		if(n==0) break;
		a=0;m=0;D=0;
		for(int i = 0;i < n;i++){
			cin >> s[i];
			m += s[i];
		}
		m/=n;
		for(int i = 0;i < n;i++){
			a += pow((s[i]-m),2) ;
		}
		a/=n;
		D=sqrt(a);
		printf("%.8f\n",D);
	}
	return 0;
}
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
long long n,m,t;
int main(){
	scanf("%lld",&n);
	m=sqrt(n);
	if(m*m==n){
		cout<<2*m-2<<endl;
		return 0;
	}else{
		for(int i=m;i>=1;i--){
			if((n/i)*i==n){
				cout<<i+n/i-2<<endl;
				break;
			}
		}
	}
	return 0;
}
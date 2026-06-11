#include<bits/stdc++.h>
#define ll long long 
#define MAXN 200010
using namespace std;

int n,m;

ll gcd(ll a,ll b){
	return b? gcd(b,a%b) : a;
}



int main(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	ll c=gcd(a,b);
	ll cnt=0;
	for(int i=2;i<=sqrt(c);i++){
		if(c%i==0){
			cnt++;
			while(c%i==0){
	//		printf("::%d\n",i);
	//		cnt++;
			c/=i;
			if(c==1)break;
		}
		}
		
	}
	if(c>1) cnt++;
	printf("%lld",cnt+1);
}
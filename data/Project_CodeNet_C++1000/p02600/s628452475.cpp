#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(int i=a;i<=b;i++)
inline ll r() {
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*f;
}
#define d r()
ll n;
int main(){
	n=d;
	if(n>=400&&n<=599)cout<<8;
	if(n>=600&&n<=799)cout<<7;
	if(n>=800&&n<=999)cout<<6;
	if(n>=1000&&n<=1199)cout<<5;
	if(n>=1200&&n<=1399)cout<<4;
	if(n>=1400&&n<=1599)cout<<3;
	if(n>=1600&&n<=1799)cout<<2;
	if(n>=1800&&n<=1999)cout<<1;
	return 0;
}
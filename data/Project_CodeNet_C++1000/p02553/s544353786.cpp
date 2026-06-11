#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

typedef long long ll;

ll a,b,c,d;
int main(){
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	ll x1,x2,x3,x4;
	x1=a*c;
	x2=a*d;
	x3=b*c;
	x4=b*d;
	ll ans;
	ans=max(max(x1,x2),max(x3,x4));
	printf("%lld",ans);
	return 0;	
}
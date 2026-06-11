#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(int argc, char** argv) {
	int n;
	cin>>n;
	ll ans=0,v=0;
	rep(i,1,n)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ans+=x*y;
		v+=y;
	}
	ll k=0;
	while(ans/10)
	{
		k+=ans/10;
		ans=ans/10+ans%10;
	};
	cout<<v-1+k;
	return 0;
}
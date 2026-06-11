#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll a[maxn];
int main(){
	ll n,m;
	ll x=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(x>1e9) continue;
		x=x*a[i]/2/__gcd(x,a[i]/2);
	}
	int flag=0;
	for(int i=0;i<n;i++){
		ll t=x*2/a[i];
		if(t%2==0){
			flag=1;
			break;
		}
	}
	if(flag) {
		printf("0\n");
		return 0;
	}
	ll k=m/x;
	if(k&1) printf("%lld\n",k/2+1);
	else printf("%lld\n",k/2);
}
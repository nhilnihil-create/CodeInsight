#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll a[maxn];
int main(){
	ll n,m;
	cin>>n>>m;
	ll lcm=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(lcm>1e9) continue;
		lcm=lcm*a[i]/2 / __gcd(lcm,a[i]/2);
	}
	bool flag=0;
	for(int i=0;i<n;i++){
		ll t=lcm*2/a[i];
		if(t%2==0){
			flag=1;
			break;
		}
	}
	ll ans=m/lcm;
	if(ans&1) ans=ans/2+1;
	else ans/=2;
	if(flag) cout<<"0"<<"\n";
	else cout<<ans<<"\n";
	return 0;
}
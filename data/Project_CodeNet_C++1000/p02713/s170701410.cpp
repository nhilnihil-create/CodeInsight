#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll i, ll j, ll k){
	return __gcd(i,__gcd(j,k));
}
void solve(){
	ll k;
	cin>>k;
	ll ans = 0;
	for(ll i=1;i<=k;++i){
		for(ll j=1;j<=k;++j){
			for(ll h = 1;h<=k;++h){
				ans += gcd(i,j,h);
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{

  solve();

return 0;
}


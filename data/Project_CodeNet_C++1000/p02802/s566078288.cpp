#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

bool ac[100010];
ll wa[100010];
int main() {
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll x;string s;
		cin>>x>>s;
		x--;
		if(ac[x]==true){
			continue;
		}
		if(s=="AC"){
			ac[x]=true;
		}
		else if(s=="WA"){
			if(ac[x]==false){
				wa[x]++;
			}
		}
	}
	ll ans=0;
	ll cnt=0;
	for(ll i=0;i<n;i++){
		if(ac[i]){
			cnt++;
			ans+=wa[i];
		}
	}
	cout << cnt<< " "<<ans;
	return 0;
}
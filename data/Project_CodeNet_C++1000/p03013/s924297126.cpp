#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mtv(kit) cout<<#kit<<" - "<<kit<<"\n";
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map

void doit(){
	ll n, i, m, x;
	cin >> n >> m;
	map<ll,ll>mp;
	rep(i,0,m){
		cin >> x;
		mp[x] = 1;
	}
	ll mod = 1e9 + 7;
	vector<ll>ans(n+2);
	ans[0] = 1;
	if(mp[1] == 0)ans[1] = 1;
	rep(i,2,n+1){
		if(mp[i] == 1)continue;
		else ans[i] = (ans[i-1] + ans[i-2]) % mod;
	}
	cout << ans[n] << nl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}

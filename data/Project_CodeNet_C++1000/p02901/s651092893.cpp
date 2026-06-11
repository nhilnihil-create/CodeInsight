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

ll dp[1005][9000];
ll keys[1005], cost[1005];
ll boxes,m;
ll ans, total;

ll F(ll cur, ll in){
	if(in == m){
		if(cur == total)return 0;
		else return 1e15;
	}
	if(dp[in][cur] != -1)return dp[in][cur];
   	ll a = F(cur,in + 1);	
	ll b = F(cur | keys[in], in + 1) + cost[in];
	return dp[in][cur] = min(a,b);
}

void doit(){
	cin >> boxes;
	ll i;
	rep(i,0,boxes)total |= 1LL << i;
	cin >> m;
	rep(i,0,m){
		ll x, C;
		cin >> cost[i] >> x;
		ll j, cur = 0;
		rep(j,0,x){
			cin >> C;
			cur |= (1LL << (C - 1));
		}
		keys[i] = cur;
	}
	memset(dp, -1, sizeof(dp));
	ans = 1e15;
	ans = F(0,0);
	if(ans == 1e15)cout << -1 << nl;
	else cout << ans << nl;
}
int main() {
#ifndef ONLINE_JUDGE
//    freopen("input1.txt","r",stdin);
//    freopen("output1.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}

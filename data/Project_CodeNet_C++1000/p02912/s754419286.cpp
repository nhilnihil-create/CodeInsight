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
	ll n, m, i, ans = 0;
	cin >> n >> m;
	priority_queue<ll>pq;
	rep(i,0,n){
		cin >> ans;
		pq.push(ans);
	}
	rep(i,0,m){
		ll k = pq.top();
		pq.pop();
		k /= 2;
		pq.push(k);
	}
	ans = 0;
	while(!pq.empty()){
		ans += pq.top();
		pq.pop();
	}
	cout << ans << nl;
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

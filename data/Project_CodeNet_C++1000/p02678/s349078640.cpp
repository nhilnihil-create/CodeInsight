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

const ll N = 1e5 + 5;
vector<ll>adj[N];

void doit(){
	ll nodes, edges, i;
	cin >> nodes >> edges;
	ll x, y;
	rep(i,0,edges){
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	queue<ll>q;
	q.push(1LL);
	vector<ll>dist(N);
	ll vis = 1;
	dist[1] = 1;
	while(!q.empty()){
		ll cur = q.front();
		q.pop();
		for(auto x : adj[cur]){
			if(dist[x] == 0){
				vis++;
				dist[x] = cur;
				q.push(x);
			}
		}
	}
	// mtv(vis)
	if(vis != nodes){
		cout << "No" << nl;
		return;
	}
	cout << "Yes" << nl;
	rep(i,2,nodes+1)cout << dist[i] << nl;

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

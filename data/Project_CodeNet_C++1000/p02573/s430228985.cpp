#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef vector<string> vsi;
typedef map<ll, ll> mape;
#define rep(i, a, b) for(ll i=(ll)a;i<=(ll)b;i++)
#define per(i, a, b) for(ll i=(ll)a;i>=(ll)b;i--)
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define all(v) v.begin(), v.end()
#define N 200010
#define pb push_back 
#define MAX 1234567890
#define mod 1000000007

vi edge[N];
vi visited(N);

ll dfs(ll n)
{
	visited[n] = 1;
	ll cnt = 0;
	for(ll i=0;i<edge[n].size();i++){
		if(!visited[edge[n][i]]) 
			cnt = cnt + dfs(edge[n][i]);
	}
	return 1ll+cnt;
}


int main()
{
    fastio;
    
    ll n, m;
    cin >> n >> m;
    ll x, y;
    rep(i, 0, m-1) {
    	cin >> x >> y;
    	edge[x].pb(y);
    	edge[y].pb(x);
	}
	ll mx = -1;
	rep(i, 1, n){
		if(!visited[i]) mx = max(mx, dfs(i));
	}
	cout << mx << endl;
    
    return 0;
}
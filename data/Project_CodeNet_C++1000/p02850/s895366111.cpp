// READ & UNDERSTAND
// ll, int overflow, array bounds
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

ll INF=LLONG_MAX;

int const mxn=1e5+5;

vector<ii>adj[mxn];
int ans = 0;
int color[mxn];

void dfs(int u, int par){
	int cnt=1;
	for(ii &j:adj[u]){
		if(color[par]==cnt)cnt++;
		int v = j.fi;
		int ind = j.se;
		if(ind==par)continue;
		color[ind]=cnt;
		cnt++;
		dfs(v,ind);
	}
	ans = max(cnt-1,ans);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,u,v; cin >> n;
	for(int i=0; i<n-1; i++){
		cin >> u >> v;
		color[i]=0;
		adj[u].pb(ii(v,i));
		adj[v].pb(ii(u,i));
	}
	dfs(1,-1);
	cout << ans << endl;
	for(int i=0; i<n-1; i++){
		cout << color[i] << endl;
	}
}	

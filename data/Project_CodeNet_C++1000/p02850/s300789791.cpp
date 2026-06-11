#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;
const int mxn=1e5+5;

vector<ii> adj[mxn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,a,b; cin >> n;
	for(int i=0; i<n-1; i++){
		cin >> a >> b;
		a--; b--;
		adj[a].eb(b,i);
		adj[b].eb(a,i);
	}
	int mx = 0;
	for(int i=0; i<n; i++){
		mx = max(mx,(int)adj[i].size());
	}
	int color[n-1];
	memset(color,-1,sizeof(color));
	for(int u=0; u<n; u++){
		set<int>cur;
		for(ii x:adj[u]){
			int ind = x.se;
			if(color[ind]!=-1)cur.insert(color[ind]);
		}
		int ptr = 0;
		while(cur.count(ptr))ptr++;
		for(ii x:adj[u]){
			int ind = x.se;
			if(color[ind]==-1){
				color[ind]=ptr;
				ptr++;
			}
			while(cur.count(ptr))ptr++;
		}
	}
	cout << mx << '\n';
	for(int i=0; i<n-1; i++){
		cout << color[i]+1 << '\n';
	}
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN

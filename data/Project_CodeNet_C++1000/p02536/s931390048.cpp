#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define endl '\n'
#define snd second
#define fst first
#define fastio cin.tie(NULL),cout.sync_with_stdio(true)

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair <int, int> ii;

const int mod = 1e9 + 7;
const ll INF = (1LL<<50);
const double EPSILON = 0.001;
const int N = 100005;
int see[N];
vi adj[N];
void dfs(int x){
	see[x] = 1;
	for(int i:adj[x]){
		if(!see[i])
			dfs(i);
	}
}
int main(){
	fastio;
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x,y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(!see[i]){
			dfs(i);
			ans++;
		}
	}
	cout << ans-1 << '\n';
	return 0;
}

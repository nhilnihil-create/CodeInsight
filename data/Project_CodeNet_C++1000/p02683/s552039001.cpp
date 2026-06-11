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
const int N = 200005;
int v[30][30];
int cost[30];
int n, m, x;
ll solve(int idx, int mask){
	vi sum(m);
	for(int i = 0; i <= n; i++){
		if((1<<i)&mask){
			for(int j = 0; j <= m; j++){
				sum[j] += v[i][j];
			}
		}
	}
	int fins = 1;
	for(int j = 0; j < m; j++){
		if(sum[j] < x)fins = 0;
	}
	if(fins){
		return 0;
	} else if(idx == n){
		return mod;
	}
	ll ans = solve(idx+1, mask); // ignore
	ans = min(ans, solve(idx+1, mask + (1<<idx)) + cost[idx]);
	return ans;
}
int main(){
	fastio;
	cin >> n >> m >> x;
	for(int i = 0; i < n; i++){
		cin >> cost[i];
		for(int j = 0; j < m; j++){
			cin >> v[i][j];
		}
	}
	ll ans = solve(0,0);
	if(ans >= mod){
		cout << -1 << "\n";
	}else
		cout << ans << '\n';
	return 0;
}

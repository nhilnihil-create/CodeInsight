#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<tuple>
#include<sstream>
#include<functional>
#include<list>
#include<queue>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> p;
typedef pair<int, pair<int, pair<int, int>>> PP;
typedef vector<int> vec;
using Graph = vector<vector<int>>;
using graph = vector<vector<ll>>;

const long long INF = 1LL << 60;
const int inf = 1e9;
const long long MOD = 1e9+7;

int n;
int cnt = 0;
Graph G;
vec seen;
int dfs(int s) {
	seen[s] = 1;
	cnt++;
	rep(i, G[s].size()) {
		if (seen[G[s][i]])continue;
		dfs(G[s][i]);
	}
	return cnt;
}


int main() {
	int m;
	int ans = 0;
	cin >> n >> m;
	G.resize(n);
	seen.assign(n, 0);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rep(i, n) {
		if (!seen[i]) {
			cnt = 0;
			int a = dfs(i);
			ans = max(a, ans);
		}
	}
	cout << ans << endl;
	return 0;
}
#include"bits/stdc++.h"
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
typedef pair<int, int> P;

lint N;
const lint MAXN = 1005;
const lint MAXV = MAXN * (MAXN - 1) / 2;
int dp[MAXV];
vector<lint> to[MAXV];
lint id[MAXN][MAXN];
bool visited[MAXV];
bool calculated[MAXV];

int ToID(int i, int j) {
	if (i > j) swap(i, j);
	return id[i][j];
}

int dfs(int v) {
	if (visited[v]) {
		if (!calculated[v]) return -1;
		return dp[v];
	}
	visited[v] = true;
	dp[v] = 1;
	for (auto u : to[v]) {
		int res = dfs(u);
		if (res == -1) return -1;
		dp[v] = max(dp[v], res + 1);
	}
	calculated[v] = true;
	return dp[v];
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	vector<vector<int>> vec(N, vector<int>(N-1));
	REP(i, N) {
		REP(j, N - 1) {
			cin >> vec[i][j];
			vec[i][j]--;
		}
	}

	int V = 0;
	REP(i, N) {
		REP(j, N) {
			if (i < j) {
				id[i][j] = V++;
			}
		}
	}
	REP(i, N) {
		REP(j, N - 1) {
			vec[i][j] = ToID(i, vec[i][j]);
		}
		REP(j, N - 2) {
			to[vec[i][j + 1]].push_back(vec[i][j]);
		}
	}
	int ans = 0;
	REP(i, V) {
		int res = dfs(i);
		if (res == -1) {
			cout << -1;
			return 0;
		}
		ans = max(ans, dfs(i));
	}
	cout << ans;
}

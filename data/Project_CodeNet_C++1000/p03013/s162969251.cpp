#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;
typedef int64_t ll;
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll mod = 1e9 + 7;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> oks(N + 1, true);
	for (int i = 0; i < M; i++)
	{
		int a; cin >> a;
		oks[a] = false;
	}

	vector<ll> dp(N + 1);
	dp[0] = 1;
	for (int now = 0; now < N; ++now) {
		for (int next = now+1;  next <= min(N,now+2);  next++)
		{
			if (oks[next])
			{
				dp[next] += dp[now];
				dp[next] %= mod;
			}
		}
	}
	cout << dp[N] << endl;
	return 0;
}

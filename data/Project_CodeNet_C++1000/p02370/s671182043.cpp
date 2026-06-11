#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <fstream>
#include <bitset>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;
const long long MOD = 1000000007LL;
const long long MAX = 500000LL;
using namespace std;
typedef unsigned long long ull;
typedef  long long ll;


int main()
{
	ll N, M;
	cin >> N >> M;
	vector<vector<ll>> g(N);
	vector<ll> idg(N, 0);
	vector<ll> dp(N, -1);
	vector<ll> to;
	for (ll i = 0; i < M; i++) {
		ll a, b;
		cin >> a >> b;

		g[a].push_back(b);
		idg[b]++;
	}
	queue<ll> q;
	for (ll i = 0; i < N; i++) {
		if (idg[i] == 0) {
			dp[i] = 0;
			q.push(i);
			to.push_back(i);
		}
	}
	while (!q.empty()) {
		ll x = q.front();
		q.pop();
		for (ll xx : g[x]) {
			idg[xx]--;
			if (idg[xx] == 0) {
				q.push(xx);
				to.push_back(xx);
			}
		}
	}
	for (ll i = 0; i < to.size(); i++) {
		cout << to[i] << endl;
	}
	return 0;
}


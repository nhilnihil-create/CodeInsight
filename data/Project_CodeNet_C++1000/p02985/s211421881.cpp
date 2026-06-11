#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>
#include <cmath>
#include <numeric>

using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)n;++i)
#define rep1(i, n) for (int i=1;i<=(int)n;++i)
#define rrep(i, n) for (int i=(int)n-1;i>=0;--i)
#define rrep1(i, n) for (int i=n;i>=1;--i)
#define range(i, l, r) for (int i=l;i<(int)r;++i)
#define rrange(i, l, r) for (int i=(int)r-1;i>=(int)l;--i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using vi=vector<int>;
using pii=pair<int, int>;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}
constexpr int TEN(int n){return n==0?1:10*TEN(n-1);}

const int inf = TEN(9) + 10;
const int mod = TEN(9) + 7;

int N, K;
vector<int> G[100010];

int dfs(int cur, int par = -1)
{
	int res = 1;
	int mul;

	if (cur == 0) {
		mul = K - 1;
	} else {
		mul = K - 2;
	}

	for (int &nxt : G[cur]) {
		if (nxt == par) continue;

		(res *= dfs(nxt, cur)) %= mod;
		(res *= mul) %= mod;
		--mul;
	}

	return res;
}

signed main()
{
	cin >> N >> K;

	rep(i, N - 1) {
		int a, b; cin >> a >> b;
		--a, --b;

		G[a].PB(b);
		G[b].PB(a);
	}

	cout << K * dfs(0) % mod << endl;
}

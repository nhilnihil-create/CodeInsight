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

using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)n;++i)
#define rep1(i, n) for (int i=1;i<=(int)n;++i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using ll=long long;
using vi=vector<int>;
using pii=pair<int, int>;

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
ll read(){ll a;scanf("%lld",&a);return a;}

const int inf = TEN(9) + 10;
const int mod = TEN(9) + 10;

int N, K, C;
string S;
int dp[200010], dp_rev[200010];
int rui[200010];

signed main()
{
	cin >> N >> K >> C;
	cin >> S;

	S = '?' + S;

	rep1(i, N) {
		dp[i] = S[i] == 'o';
		if (i - C - 1 >= 1) dp[i] += dp[i - C - 1];
		chmax(dp[i], dp[i - 1]);
	}

	for (int i = N; i >= 1; --i) {
		dp_rev[i] = S[i] == 'o';
		if (i + C + 1 <= N) dp_rev[i] += dp_rev[i + C + 1];
		chmax(dp_rev[i], dp_rev[i + 1]);
	}

	rep1(i, N) {
		if (S[i] == 'x') continue;
		if (dp[i - 1] + dp_rev[i + 1] < K) {
			printf("%lld\n", i);
		}
	}
}



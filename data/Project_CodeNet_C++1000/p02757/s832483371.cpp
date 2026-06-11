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

const int inf = 3 * TEN(18) + 10;
const int mod = 998244353;

int N, P;
string S;
int rui[200010];
int counter[10010];

signed main()
{
	cin >> N >> P;
	cin >> S;

	int ans = 0;

	if (P == 2) {
		rep(i, N) {
			if ((S[i] - '0') % 2 == 0) {
				ans += i + 1;
			}
		}
	} else if (P == 5) {
		rep(i, N) {
			if ((S[i] - '0') % 5 == 0) {
				ans += i + 1;
			}
		}
	} else {
		S = ' ' + S;

		counter[0]++;
		int ten = 1;
		for (int i = N; i >= 1; --i) {
			rui[i] += rui[i + 1];
			rui[i] += (S[i] - '0') * ten;
			rui[i] %= P;

			ans += counter[rui[i]];
			counter[rui[i]]++;

			ten *= 10;
			ten %= P;
		}
	}

	cout << ans << endl;
}




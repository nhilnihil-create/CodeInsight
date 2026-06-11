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
#include <numeric>
#include <iomanip>
#include <climits>
#include <cstring>

using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)(n);++i)
#define rep1(i, n) for (int i=1;i<=(int)(n);++i)
#define rrep(i, n) for (int i=(int)(n)-1;i>=0;--i)
#define rrep1(i, n) for (int i=(int)(n);i>=1;--i)
#define range(i, l, r) for (int i=l;i<(int)(r);++i)
#define rrange(i, l, r) for (int i=(int)(r)-1;i>=l;--i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using vi=vector<int>;
using pii=pair<int, int>;
using vpii=vector<pii>;
using ll=long long;

constexpr int TEN(int n){return n==0?1:10*TEN(n-1);}
bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

const int inf = TEN(18)*3+10;

int N;
int A[100010];

signed main()
{
	cin >> N;
	rep(i, N + 1) cin >> A[i];

	int sum = accumulate(all(A), 0ll);

	int ans = 0;
	int c = 1;

	rep(i, N + 1) {
		ans += c;
		c -= A[i];

		if (c < 0) {
			puts("-1");
			return 0;
		}

		sum -= A[i];
		c = min(2 * c, sum);
	}

	cout << ans << endl;
}



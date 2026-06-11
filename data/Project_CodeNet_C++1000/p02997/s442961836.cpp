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

int N, K;

signed main()
{
	cin >> N >> K;

	int counter = (N - 1) * (N - 2) / 2;

	if (counter < K) {
		cout << -1 << endl;
		return 0;
	}

	vector<pii> edges;

	for (int i = 2; i <= N; ++i) {
		edges.PB(1, i);
	}

	int cur = 2;

	while (counter != K) {
		for (int i = cur; i + 1 <= N; ++i) {
			edges.PB(cur, i + 1);
			counter--;
			if (counter == K) break;
		}
		cur++;
	}

	cout << edges.size() << endl;
	for (auto &&e : edges) {
		printf("%lld %lld\n", e.fst, e.scd);
	}
}

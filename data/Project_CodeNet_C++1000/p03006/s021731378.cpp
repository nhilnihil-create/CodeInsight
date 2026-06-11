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
#include <unordered_map>

using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)(n);++i)
#define rep1(i, n) for (int i=1;i<=(int)(n);++i)
#define range(i, l, r) for (int i=l;i<(int)(r);++i)
#define rrange(i, l, r) for (int i=r-1;i>=(int)(l);--i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using vi=vector<int>;
using pii=pair<int, int>;
using ll=long long;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
//int read(){int a;scanf("%lld",&a);return a;}

constexpr int TEN(int n){return n==0?1:10*TEN(n-1);}

const int inf = TEN(18)*3 + 10;
const int mod = TEN(9) + 7;

map<pii, bool> exists;
map<pii, bool> used;

int ans;

void dfs(pii point, int p, int q, int depth = 0)
{
	if (used.count(point) > 0) {
		return;
	}
	if (exists.count(point) == 0) {
		return;
	}
	if (depth == 0) ans++;
	used[point] = true;
	
	dfs(pii(point.fst + p, point.scd + q), p, q, depth + 1);
	dfs(pii(point.fst - p, point.scd - q), p, q, depth + 1);
}

signed main()
{
	int N; cin >> N;
	vector<pii> points;
	rep(i, N) {
		int x, y; cin >> x >> y;
		points.PB(x, y);
		exists[pii(x,y)] = true;
	}

	if (N == 1)
	{
		puts("1");
		return 0;
	}

	int mn = inf;
	rep(i, N) {
		rep(j, i) {
			int p = points[i].fst - points[j].fst;
			int q = points[i].scd - points[j].scd;

			used.clear();
			ans = 0;
			rep(k, N) {
				dfs(points[k], p, q);
			}
			chmin(mn, ans);
		}
	}

	cout << mn << endl;
}

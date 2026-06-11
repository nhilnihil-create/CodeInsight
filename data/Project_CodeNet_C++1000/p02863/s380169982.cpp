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

using vi=vector<int>;
using pii=pair<int, int>;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int dp[6010];

int N,T;
int a[3010], b[3010];

signed main()
{
	cin >> N >> T;
	vector<pii> menu;
	rep1(i, N) {
		cin >> a[i] >> b[i];
		menu.PB(pii(a[i], b[i]));
	}

	sort(all(menu));

	rep1(i, N) {
		for (int t = T - 1; t >= 0; --t) {
			chmax(dp[t + menu[i-1].fst], dp[t] + menu[i-1].scd);
		}
	}

	int mx = 0;
	for (int i = 6005; i >= 0; --i) {
		chmax(mx, dp[i]);
	}

	cout << mx << endl;
}

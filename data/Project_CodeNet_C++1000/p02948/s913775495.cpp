#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define dump(x)  cout << #x << " = " << (x) << endl;	//debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, start_index, num)  (a).begin()+(start_index),(a).begin()+(num)


int main() {
	vector<pair<int, int>> ab;
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n) {
		int a, b;
		cin >> a >> b;
		ab.push_back(MP(a, b));
	}
	sort(ALL(ab));
	priority_queue<int> pq;

	int starti = 0;
	int now = 1;
	ll res = 0;
	while (1) {
		FOR(i, starti, n - 1) {
			if (ab[i].F == now) {
				pq.push(ab[i].S);
			}
			else {
				starti = i;
				break;
			}
		}
		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
		now++;
		if (now == m + 1)break;
	}
	pv(res);
}
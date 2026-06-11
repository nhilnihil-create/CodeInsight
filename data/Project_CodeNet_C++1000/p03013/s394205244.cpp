#include "bits/stdc++.h"

#define REP(i,n) for(int i=0;i< (n);i++)
#define REPR(i, n) for(int i = (n);i >= 0;i--)
#define FOR(i, m, n) for(int i = (m);i < (n);i++)
#define FORR(i, m, n) for(int i = (m);i >= (n);i--)
#define SORT(v, n) std::sort(v, v+n);
#define VSORT(v) std::sort(v.begin(), v.end());
#define VRSORT(v) std::sort(v.rbegin(), v.rend());
#define ll long long
#define pb(a) push_back(a)
#define ALL(obj) (obj).begin(),(obj).end()

using namespace std;

const int INF = 99999999;
const ll LINF = 9999999999999;

typedef pair<ll, ll> LP;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

ll N, M, a[110000] = {};
int main() {
	cin >> N >> M;
	REP(i, 110000) {
		a[i] = INF;
	}
	REP(i, M) {
		ll tmp;
		cin >> tmp;
		a[tmp] = 0;
	}

	a[0] = 1;
	if (a[1] == INF) a[1] = 1;
	FOR(i,2, N+2) {
		if (a[i] == INF) {
			a[i] = a[i - 1] + a[i - 2];
			a[i] = a[i] % 1000000007;
		}
	}


	cout << a[N] << endl;

}
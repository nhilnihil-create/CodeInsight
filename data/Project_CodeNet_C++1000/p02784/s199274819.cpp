#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int h, n; cin >> h >> n;
	int cnt = 0;
	REP(i, n) {
		int a;
		cin >> a;
		cnt += a;
		if (cnt >= h) {
			cout << "Yes" << endl;
			break;
		}
	}
	if (cnt < h) {
		cout << "No" << endl;
	}
}
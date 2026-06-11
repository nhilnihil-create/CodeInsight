#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	long double w, h, x, y;
	int k = 0;
	cin >> w >> h >> x >> y;
	long double S = h / 2.0 * w;
	if (h / 2 == y && w / 2 == x)k = 1;

	cout << fixed << setprecision(12) << S;
	cout << " " << k << endl;
	return 0;
}


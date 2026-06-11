#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	double w, h, x, y;
	cin >> w >> h >> x >> y;
	double ans = w / 2 * h;
	bool ok = (x == w/2 && y == h/2);
	cout << fixed << setprecision(12) << ans << " " << (ok ? "1" : "0") << endl;
	return 0;
}
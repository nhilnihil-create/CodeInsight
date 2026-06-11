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
	double a, b, x;
	cin >> a >> b >> x;
	x /= a;
	double rad = (x <= a*b/2 ? atan2(b*b, 2*x) : atan2(2*(a*b-x), a*a));
	double ans = rad / (2*acos(-1)) * 360;
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}

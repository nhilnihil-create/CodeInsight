#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int w, h, x, y;
	cin >> w >> h >> x >> y;

	double ans = (double)w*h/2;
	int res = 0;
	if(w%2 != 0 || h%2 != 0) res = 0;
	else if(x == w/2 && y == h/2) res = 1;

	if(res) cout << fixed << setprecision(10) << ans << " " << res << endl;
	else cout << fixed << setprecision(10) << ans << " " << res << endl;

	return 0;
}
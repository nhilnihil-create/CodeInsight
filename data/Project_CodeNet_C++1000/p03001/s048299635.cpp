#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	ll W, H, x, y;
	cin >> W >> H >> x >> y;

	double ans = 0.5*W*H;
	int c = W==2*x && H==2*y;
	cout << setprecision(10) << ans << " " << c << endl;

return 0;
}

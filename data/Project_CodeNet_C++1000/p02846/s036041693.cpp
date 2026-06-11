#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
	lint t1, t2; cin >> t1 >> t2;
	lint a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
	lint P = (a1 - b1) * t1;
	lint Q = (a2 - b2) * t2;
	if(P > 0) P *= -1, Q *= -1;
	if(P == -Q){
		cout << "infinity" << endl;
		return 0;
	}
	if(P + Q < 0){
		cout << 0 << endl;
		return 0;
	}
	lint ans = 0;
	lint S = -P / (P + Q), T = -P % (P + Q);
	if(T == 0) ans = S * 2;
	else ans = S * 2 + 1;
	cout << ans << endl;
}

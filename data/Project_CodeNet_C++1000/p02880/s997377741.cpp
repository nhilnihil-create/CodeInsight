#include <bits/stdc++.h>
using namespace std;

signed main(){
#ifdef _DEBUG
	//freopen("_in" , "r", stdin );
	//freopen("_out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= 9; i++) {
		if (n % i == 0 && n / i >= 1 && n / i <= 9) {
			cout << "Yes\n";\
			return 0;
		}
	}
	cout << "No\n";
}

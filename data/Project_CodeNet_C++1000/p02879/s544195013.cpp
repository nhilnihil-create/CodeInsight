#include <bits/stdc++.h>
using namespace std;

signed main(){
#ifdef _DEBUG
	freopen("_in" , "r", stdin );
	//freopen("_out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b; cin >> a >> b;
	if (a >= 1 && a <= 9 && b >= 1 && b <= 9) cout << a * b << '\n';
	else cout << -1 << '\n';
}


#include <bits/stdc++.h>
#define long long long
using namespace std;

signed main(){
#ifdef _DEBUG
	//freopen("_in" , "r", stdin );
	//freopen("_out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	long n; cin >> n;
	long i = sqrt(n);
	for (; i; i--) if (n % i == 0) break;
	cout << i + n/i - 2 << '\n';
}

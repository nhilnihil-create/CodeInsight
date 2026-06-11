#include <bits/stdc++.h>
using namespace std;
#define int long long

int a, b;
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b;
	if (a >= 1 && a <= 9 && b >= 1 && b <= 9) cout << a*b;
	else cout << -1;
}
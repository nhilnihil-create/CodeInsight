#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("_in" , "r", stdin );
	freopen("_out", "w", stdout);
#endif
	int a, b; cin >> a >> b;
	cout << max(0, a - b * 2);
}

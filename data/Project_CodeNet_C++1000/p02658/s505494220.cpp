#include <bits/stdc++.h>

#define debug_input freopen("stdin.in", "w", stdin)
#define debug_output freopen("stdout.out", "w", stdout)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
	ll n, a, num;
	const ll comp = 1e18;

	cin >> n;
	cin >> a;

	bool flag = 1;
	for(int i = 1; i < n; i++) {
		cin >> num;
		if(num == 0) {
			flag = 1;
			a *= num;
			break;
		}
		else if(a <= (comp / num)) {
			a *= num;
		}
		else {
			flag = 0;
		}
	}	

	if(flag) {
		cout << a;
	}
	else cout << -1 << endl;

	return 0;
}
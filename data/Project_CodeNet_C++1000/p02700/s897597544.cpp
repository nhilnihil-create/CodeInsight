#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
//		freopen("in1.txt", "r", stdin);
//		freopen("in1.txt", "w", stdout);
	#endif
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	while (1) {
		c -= b;
		if (c<=0) {
			cout << "Yes\n";
			break;
		}
		a -= d;
		if (a<=0) {
			cout << "No\n";
			break;
		}
	}
}
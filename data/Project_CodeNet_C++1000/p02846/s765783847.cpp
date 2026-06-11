#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 10000000000000000;
const int mod = 1000000007;
int iti[12345678], cnt[12345678], cost[4321][4321];
signed main() {
	int n, t1, t2, a1, a2, b1, b2, saki = 0, ato = 0, ans = 1;
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
	int firsta = a1 * t1, firstb = b1 * t1;
	int seconda = a2 * t2, secondb = b2 * t2;
	saki = firsta - firstb; ato = seconda - secondb;
	if (saki + ato == 0) { cout << "infinity" << endl; return 0; }
	if ((firsta > firstb) && (firsta + seconda > firstb + secondb)) {
		cout << 0 << endl; return 0;
	}
	if ((firsta < firstb) && (firsta + seconda < firstb + secondb)) {
		cout << 0 << endl; return 0;
	}
	//cout << saki << ' ' << ato << endl;
	//cout << saki + ato << endl;
	if (saki % (saki + ato) == 0) {
		cout << abs(saki / (saki + ato)) * 2 << endl;
	}
	else {
		cout << abs(saki / (saki + ato)) * 2 + 1 << endl;
	}
	cin >> n; return 0;
}
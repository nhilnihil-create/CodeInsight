
#include<bits/stdc++.h>
#include<array>
using namespace std;
using UL = unsigned;
using LL = long long;
using ULL = unsigned long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)
void Solve() {
	LL t1, t2; cin >> t1 >> t2;
	LL a1, a2; cin >> a1 >> a2;
	LL b1, b2; cin >> b1 >> b2;
	LL a = a1 - b1; LL b = a2 - b2;
	LL d = a * t1 + b * t2;
	if (d == 0) { cout << "infinity" << endl; return; }
	if (double(a) * double(b) > 0.0) { cout << 0 << endl; return; }
	if (double(a) * double(d) > 0.0) { cout << 0 << endl; return; }
	LL df = abs(a * t1);
	d = abs(d);
	LL ans = df / d + (df - 1) / d + 1;
	cout << ans << endl;
}
int main() { Solve(); return 0; }

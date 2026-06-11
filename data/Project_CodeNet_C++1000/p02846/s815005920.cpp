#include<bits/stdc++.h>
#define puts(x) cout << x << "\n"
using namespace std;
long long t1, t2, a1, a2, b1, b2;
int main() {
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
	a1 = (a1 - b1) * t1;
	a2 = (a2 - b2) * t2;
	if (a1 + a2 == 0)puts("infinity");
	else if (a1/abs(a1) * a2 > 0 || abs(a1) > abs(a2))puts(0);
	else {
		long long ans = (abs(a2) / abs(a1 + a2)) * 2 - 1;
		if (abs(a2) % abs(a1 + a2) == 0)ans--;
		puts(ans);
	}
}
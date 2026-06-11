#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

long long t1, t2, a1, a2, b1, b2;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t1 >> t2;
	cin >> a1 >> a2;
	cin >> b1 >> b2;
	if (a1 < b1) {
		swap(a1, b1);
		swap(a2, b2);
	}
	if ((a1 > b1 && a2 >= b2)) {
		cout << 0 << E;
		return 0;
	}
	if (a1 == b1) {
		cout << "infinity" << E;
		return 0;
	}
	if (a1*t1 + a2 * t2 == b1 * t1 + b2 * t2) {
		cout << "infinity" << E;
		return 0;
	}
	long long tmp1 = a1 * t1 - b1 * t1;
	long long tmp2 = b1 * t1 + b2 * t2 - (a1*t1 + a2 * t2);
	if (tmp2 < 0) {
		cout << 0 << E;
		return 0;
	}
	long long ans = ((tmp1  + tmp2 - 1)/ tmp2) * 2;
	if (tmp1%tmp2 == 0) ans++;
	ans--;
	cout << ans << E;
	//system("pause");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long A, B, C, D;
	cin >> A >> B >> C >> D;

	long long ans = B - A + 1;
	ans -= B / C - (A - 1) / C;
	ans -= B / D - (A - 1) / D;
	long long lcm = C / __gcd( C, D ) * D;
	ans += B / lcm - (A - 1) /lcm;

	cout << ans << endl;
}

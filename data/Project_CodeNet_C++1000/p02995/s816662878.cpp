#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a,b,c,d;
	cin >> a >> b >> c >> d;
	long long all = b-a+1,
	cd = lcm(c,d),
	bc = b/c,
	bd = b/d,
	ac = (a-1)/c,
	ad = (a-1)/d,
	bcd = b/cd,
	acd = (a-1)/cd;
	cout << all-bc-bd+bcd+ac+ad-acd << endl;
	return 0;
}

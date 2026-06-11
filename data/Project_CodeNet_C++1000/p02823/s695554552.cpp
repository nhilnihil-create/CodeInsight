#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n, a, b; cin >> n >> a >> b;
	long long res;
	if((b - a) % 2 == 0) res = (b - a) / 2;
	else {
		long long  res1, res2;
		res1 = (b - a - 1) / 2 + a;
		res2 = (b - a - 1) / 2 + (n - b) + 1;
		res = min(res1, res2);
	}
	cout << res << endl;
	return 0;
}

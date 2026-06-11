#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e7 + 10;
string n;
int len, num, i, f[N][2];
int main() {
	cin >> n;
	len = n.size();
	f[0][0] = 0; f[0][1] = 1;
	for (i = 0; i < len; i++) {
		num = n[i] - '0';
		f[i + 1][0] = min(f[i][0] + num, f[i][1] + 10 - num);
		f[i + 1][1] = min(f[i][0] + num + 1, f[i][1] + 9 - num);
	}
	cout << f[len][0];
	return 0;
}
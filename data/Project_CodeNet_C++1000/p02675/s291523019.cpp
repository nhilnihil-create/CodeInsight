#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 998244353

using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	n %= 10;
	if (n == 3) cout << "bon";
	else if (n == 0 || n == 1 || n == 6 || n == 8) cout << "pon";
	else cout << "hon";
	cout << endl;
	return 0;
}

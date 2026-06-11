#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll unsigned long long

const ll MOD = 1000000000000000000;

int main() {
	//入力
	ll n,a,b;
	cin >> n >> a >> b;

	//処理
	ll x = 0;
	ll ans = 0;
	x = floor(n / (a + b));
	if (n - (a + b) * x <= a)
		ans = x * a + n - (a + b) * x;
	else
		ans = x * a + a;

	//出力
	cout << ans << endl;

	return 0;
}
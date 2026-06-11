#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll unsigned long long

const int MOD = 1000000007;

int main() {
	//入力
	int k;
	cin >> k;

	//処理
	string ans="";
	rep(i, k) {
		ans += "ACL";
	}
	//出力
	cout << ans << endl;

	return 0;
}
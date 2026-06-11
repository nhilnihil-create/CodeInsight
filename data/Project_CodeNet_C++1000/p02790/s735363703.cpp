#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int a, b;
	cin >> a >> b;
	string s_a, s_b;
	rep(i, b) s_a += '0' + a;
	rep(i, a) s_b += '0' + b; 
	string ans;
	if (s_a < s_b) ans = s_a;
	else ans = s_b;
	cout << ans << endl;
	return 0;
}

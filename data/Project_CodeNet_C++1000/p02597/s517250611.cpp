#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repbit(bit,n) for (int bit = 0; bit < (1<<n); bit++)
using namespace std;
typedef long long ll;

const int INF = 1001001001;
//const ll INF = 1000000000000000000;

int main() {
	int n;
	string s;
	cin >> n >> s;

	int left_w = 0, right_r = 0;
	rep(i,s.size()) {
		if (s[i] == 'R') right_r++;
	}
	int ans = max(left_w, right_r);
	rep(i,s.size()) {
		if (s[i] == 'W') left_w++;
		else right_r--;
		ans = min(ans, max(left_w, right_r));
	}
	cout << ans << endl;
	return 0;
}

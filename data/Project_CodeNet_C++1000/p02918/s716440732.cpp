#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	int cnt = 0;
	rep(i,n-1) {
		if (s[i] != s[i+1]) cnt++;
	}
	int ans = n-1 - max(0,cnt-2*k);
	cout << ans << endl;
	return 0;
}
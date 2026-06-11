#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	rep(i,n) cout << s[i] << t[i];
	cout << endl;
	return 0;
}
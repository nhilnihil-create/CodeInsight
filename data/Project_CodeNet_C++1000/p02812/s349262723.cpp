#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
#define all(x) x.begin(), x.end()

signed main() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	rep(i, n-2){
		if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') ans++;
	}
	cout << ans << endl;
}

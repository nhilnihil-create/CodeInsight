#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	string s;
	cin >> s;
	string ans = "Yes";
	int n = s.size();
	rep(i, (n - 1)/2) {
		if (s[i] != s[n - i - 1] || s[i] != s[(n - 1)/2 - i - 1] || s[i] != s[(n - 1)/2 + i + 1]){
			ans = "No";
			break;
		}
	}
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	string n, s, ans = "No";
	cin >> n >> s;
	if(n == s.substr(0,n.size()))ans = "Yes";
	cout << ans << endl;
	return 0;
}

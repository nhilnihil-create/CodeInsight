#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	string s, t; cin >> s >> t;
  	cout << (t.substr(0, (int)(s.size())) == s ? "Yes" : "No") << endl;
  	return 0;
}

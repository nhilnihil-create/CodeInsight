#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; string s; cin >> n >> s;
	string abc = "ABC";
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		string tmp = s.substr(i, 3);
		if (tmp == abc) ans++;
	}
	cout << ans << endl;
    return 0;
}
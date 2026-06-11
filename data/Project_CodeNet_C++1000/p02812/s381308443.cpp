#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(10)





void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string k = "ABC";
	int cnt = 0;
	for(int i = 0; i + k.length() <= s.length(); i++) {
		bool ok = 1;
		for(int j = 0; j < k.length(); j++) {
			if(s[i + j] != k[j]) {
				ok = 0;
				break;
			}
		}
		if(ok) {
			cnt++;
		}
	}
	cout << cnt << "\n";


	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	solve();

	return 0;
}
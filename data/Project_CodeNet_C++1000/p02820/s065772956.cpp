#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, k, r, s, p; cin >> n >> k >> r >> s >> p;
	string t; cin >> t;	
	vector<char> result(n, 'e');	
	int ans = 0;	
	for (int i = 0; i < t.size(); i++) {		
		if (i <= k - 1) { // k回目まで
			if (t[i] == 'r') {
				ans += p;
				result[i] = 'p';
			}
			if (t[i] == 's') {
				ans += r;
				result[i] = 'r';
			}
			if (t[i] == 'p') {
				ans += s;
				result[i] = 's';
			}
		}
		else  {  // k < i
			if (t[i] == t[i - k]) {
				if (t[i] == 'r') {
					if (result[i - k] == 'p') {}
					else {
						ans += p;
						result[i] = 'p';
					}
				}
				else if (t[i] == 's') {
					if (result[i - k] == 'r') {}
					else {
						ans += r;
						result[i] = 'r';
					}
				}
				else if (t[i] == 'p') {
					if (result[i - k] == 's') {}
					else {
						ans += s;
						result[i] = 's';
					}
				}
			}
			else { // k回前と違えばなんでも出せる
				if (t[i] == 'r') {
					ans += p;
					result[i] = 'p';
				}
				if (t[i] == 's') {
					ans += r;
					result[i] = 'r';
				}
				if (t[i] == 'p') {
					ans += s;
					result[i] = 's';
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
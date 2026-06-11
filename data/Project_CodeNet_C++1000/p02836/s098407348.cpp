#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(0)





void solve() {

	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.length() / 2; i++) {
		if(s[i] != s[s.length() - 1 - i]) {
			cnt++;
		}
	}
	cout << cnt;
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	fix;
	solve();

	return 0;
}
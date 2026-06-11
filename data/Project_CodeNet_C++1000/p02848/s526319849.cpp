#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(0)





void solve() {

	
	int n;
	string s;
	cin >> n;
	cin >> s;
	for(int i = 0; i < s.length(); i++) {
		char ch = s[i] + n;
		if(ch > 'Z') {
			ch = ch - 'Z' + 'A' - 1;
		}
		cout << ch;
	}




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	fix;
	solve();

	return 0;
}
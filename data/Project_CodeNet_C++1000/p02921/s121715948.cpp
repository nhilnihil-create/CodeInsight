#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string s, t;
	cin >> s >> t;

	int ans = 0;
	for (int ii = 0; ii < 3; ++ii){
		if (s[ii] == t[ii]){
			ans++;
		}
	}



	cout << ans << "\n";

	return 0;
}

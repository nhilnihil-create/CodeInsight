#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.size();
	int cnt = 0;
	for (int ii = 0; ii < n/2; ++ii){
		if (s[ii] != s[n-1-ii]){
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}

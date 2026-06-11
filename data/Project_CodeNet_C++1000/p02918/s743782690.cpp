#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int ans = 0;
	for (int ii = 0; ii < n-1; ++ii){
		if (s[ii] == s[ii+1]){
			ans++;
		}
	}

	cout << min(n-1, ans + 2*k) << "\n";

	return 0;
}

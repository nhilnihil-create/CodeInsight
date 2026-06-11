#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {

	string s, t; cin >> s >> t;
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != t[i]) res++;
	}

	cout << res;
	
	return 0;
}
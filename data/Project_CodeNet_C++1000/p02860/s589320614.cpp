#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n&1) return cout << "No", 0;
	cout << (s.substr(0,n/2) == s.substr(n/2,n/2) ? "Yes" : "No");
	return 0;
}

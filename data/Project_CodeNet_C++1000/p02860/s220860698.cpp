#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	string s; cin >> s;
	if (n % 2 == 1) {
		cout << "No" << endl;
		return 0;
	}
	string left = s.substr(0, n / 2);
	string right = s.substr(n / 2);
	if (left == right) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
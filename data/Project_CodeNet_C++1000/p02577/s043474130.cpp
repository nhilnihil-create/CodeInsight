#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
	string n;
	int sum = 0;
	cin >> n;

	for (int i = 0; i < n.size(); ++i) {
		sum += int(n[i]) - 48;
	}
	if (sum % 9 == 0) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
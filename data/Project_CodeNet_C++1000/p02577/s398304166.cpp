#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	cin >> n;

	long long temp = 0;

	for (int i = 0; i < n.length(); i++) {
		temp += n[i] - '0';
	}

	if (temp%9 == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
}
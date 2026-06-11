#include <bits/stdc++.h>

using namespace std;

int main() {

	string s;
	cin >> s;

	string t;
	cin >> t;

	long counter = 0;
	for (long i = 0; i < 3; i++) {
		if (s[i] == t[i]) { counter++; }
	}

	cout << counter << endl;
}
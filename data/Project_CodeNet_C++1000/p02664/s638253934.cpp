#include <iostream>
using namespace std;

string t;

int main() {
	cin >> t;
	int n = t.length();
	for (int i=0; i<n; i++) {
		if (t[i] == '?') t[i] = 'D';
	}
	cout << t << '\n';
}
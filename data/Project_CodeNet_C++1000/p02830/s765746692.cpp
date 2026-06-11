#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	string s = "";
	for (int i = 0; i < n; ++i) {
		s += a[i];
		s += b[i];
	}
	cout << s;
}

















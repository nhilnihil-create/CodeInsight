#include <bits/stdc++.h>

using namespace std;

int n, m;
int wa[105000];
bool ac[105000];

int main() {
	cin >> n >> m;
	int wac = 0;
	int acc = 0;
	for (int i = 0; i < n; i++) {
		wa[i] = ac[i] = 0;
	}
	while (m--) {
		int p;
		string s;
		cin >> p >> s;
		if (ac[p]) continue;
		if (s == "AC") {
			ac[p] = 1;
			acc++;
			wac += wa[p];
		}
		else {
			wa[p]++;
		}
	}

	cout << acc << " " << wac << endl;
}

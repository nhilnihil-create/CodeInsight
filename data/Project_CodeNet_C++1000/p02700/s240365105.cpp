#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	bool tak = 1;
	while (a > 0 && c > 0) {
		if (tak) c -= b;
		else a -= d;
		tak = !tak;
	}

	if (a <= 0) cout << "No";
	else cout << "Yes";
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 10;

int numb[MAXN];

void preclac() {
	numb[0] = 0;
	for (int i = 1; i < MAXN; i++) {
		numb[i] = numb[i - 1];
		int x = i;
		while (x % 2 == 0) {
			numb[i]++;
			x /= 2;
		}
	}
}

bool Cnk(int n, int k) {
	int a = numb[n];
	int b = numb[k] + numb[n - k];
	if (a == b)
		return 1;
	return 0;
}

int main() {
	preclac();
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - '0';
		a[i]--;
	}
	int ans = 0;
	bool flag = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0)
			continue;
		flag = 1;
		if (Cnk(n - 1, i))
			ans ^= 1;
	}
	if (ans == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (flag) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
		a[i] /= 2;
	ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0)
			continue;
		if (Cnk(n - 1, i))
			ans ^= 1;
	}
	if (ans == 1) {
		cout << 2 << endl;
	}
	else
		cout << 0 << endl;
}
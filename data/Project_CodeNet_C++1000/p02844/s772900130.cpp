#include<iostream>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;

	int ans = 0;
	for (int i = 0; i < 1000; i++) {
		int c[3] = { i / 100,(i / 10) % 10,i % 10 };
		int hit = 0;
		for (int j = 0; j < n; j++) {
			if (s[j] == ('0' + c[hit]))hit++;
			if (hit == 3)break;
		}
		if (hit == 3)ans++;
	}
	cout << ans << endl;

	return 0;
}
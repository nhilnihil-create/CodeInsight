#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	int n = S.size();
	string ans;
	for (int i = 0; i < n; i++) {
		ans += 'x';
	}
	cout << ans << endl;
}
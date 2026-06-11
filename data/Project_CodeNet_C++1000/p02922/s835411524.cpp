#include <bits/stdc++.h>

using namespace std;

int main() {
	int a,b;
	cin >> a >> b;
	int count = 1;
	int ans = 0;
	while(count < b) {
		count += a - 1;
		ans++;
	}
	cout << ans << endl;
	return 0;
}

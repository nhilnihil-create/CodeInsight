// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	long long ans = 0;
	
	for(int i = 1; i <= n; i++) {
		if(i % 3 == 0 || i % 5 == 0) continue;
		ans += i;
	}
	cout << ans;

	return 0;
}

// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long total = 0;

	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		total += 1ll * (i + 1) * (n - i);
	}

	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		if(u > v) swap(u, v);
		
		total -= 1ll * u * (n - v + 1);

	}

	cout << total;
	
	return 0;
}

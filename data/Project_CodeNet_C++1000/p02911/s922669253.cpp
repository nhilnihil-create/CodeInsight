// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k, q;
	cin >> n >> k >> q;

	vector<int> a(n);

	for(int i = 0; i < q; i++) {
		int x;
		cin >> x;
		x--;
		a[x]++;
	}

	for(int i = 0; i < n; i++) {
		if(q - a[i] >= k) {
			cout << "No\n";	
		}
		else cout << "Yes\n";
	}


	return 0;
}

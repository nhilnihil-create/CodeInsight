#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n], res[n] = {};
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(i % 2 == 0) res[0] += a[i];
		else res[0] -= a[i];
	}
	for (int i = 1; i < n; i++)
	{
		res[i] = 2 * a[i-1] - res[i-1];
	}

	for (int i = 0; i < n; i++)
	{
		cout << res[i];
		if(i != n-1) cout << " ";
		else cout << endl;
	}

	return 0;
}

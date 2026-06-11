#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
	int n, m; cin >> n >> m;
	int ng[100100] = {};
	for (int i = 0; i < m; i++)
	{
		int a; cin >> a;
		ng[a] = 1;
	}

	int res[100100];
	if(ng[1]) {
		res[1] = 0;
		if(ng[2]) res[2] = 0;
		else res[2] = 1;
	}
	else {
		res[1] = 1;
		if(ng[2]) res[2] = 0;
		else res[2] = 2;
	}

	for (int i = 3; i <= n; i++)
	{
		if(ng[i]) res[i] = 0;
		else res[i] = (res[i-1] + res[i-2]) % MOD;
	}
	cout << res[n] << endl;
	return 0;
}

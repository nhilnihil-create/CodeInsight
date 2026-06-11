#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	const int N = 1e6 + 9;
	vector< int > facs(N, 2);
	facs[0] = 0;
	facs[1] = 1;
	for(int i = 2; i < N; i ++) {
		for(int j = 2 * i; j < N; j += i)
			facs[j] ++;
	}
	//for(int i : facs) cout << i << " ";
	int n; cin >> n;
	int ans = 0;
	for(int c = 1; c < n; c ++) {
		ans += (facs[n - c]);
	}
	cout << ans << endl;


	return 0;
}
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;


int main()
{
	
	int n; cin >> n;
	int a[n+2];
	int b[n+10];
	int c[n+10];

	int res = 0;

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)  cin >> b[i];
	for (int i = 1; i <= n-1; i++)  cin >> c[i];

	int old_A = -1000;

	for (int i = 1; i <= n; i++) {

		int A = a[i];
		res += b[A];

		if (old_A + 1 == A) {
			res += c[old_A];
		}
		old_A = A;
	}

	cout << res;
	return 0;

}
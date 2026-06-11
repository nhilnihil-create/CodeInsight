#include<bits/stdc++.h>
using namespace std;

#define GO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int

const int maxr = 2e5 + 5;

int arr[maxr];
int32_t main()
{
	GO;
	int n;
	cin >> n;
	if ((n & 1))
		cout << 0 << endl;
	else {
		int count = 10, ans = 0;
		while ((n / count) > 0) {
			ans += (n / count);
			count *= 5;
		}
		cout << ans << endl;
	}
	return 0;
}

//!
#include<bits/stdc++.h>
using namespace std;

#define GO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int

const int maxr = 1e5 + 5;

int arr[maxr];
int32_t main()
{
	GO;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		int count = 0;
		while (i < n && arr[i - 1] >= arr[i]) {
			count++;
			i++;
		}
		ans = max(ans, count);
	}
	cout << ans << endl;
	return 0;
}

//!
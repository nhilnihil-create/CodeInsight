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
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int idx = 0, val = 1;
	int ans = 0;
	while (idx < n) {
		if (arr[idx] == val) {
			ans++;
			val++;
		}
		idx++;
	}
	if (ans == 0)
		cout << -1 << endl;
	else
		cout << n - ans << endl;
	return 0;
}

//!
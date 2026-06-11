#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 2e5 + 5;
int n, a[M], b[M];
 
int32_t main() 
{
	ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	cout << (n & 1 ? b[n / 2] - a[n / 2] : b[n / 2] + b[n / 2 - 1] - a[n / 2] - a[n / 2 - 1]) + 1;
    	return 0;
}
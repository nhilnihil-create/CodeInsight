#include <bits/stdc++.h>
using namespace std;
#define test() int t; cin>>t; while(t--)
#define ll long long int
int mod = 1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	cin >> a >> b;
	int ans = 0;
	int s = 1;
	while (s < b) {
		s--;
		s += a;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
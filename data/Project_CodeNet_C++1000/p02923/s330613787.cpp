#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define mod 1000000007
#define string_mod 2549536629329_base_255
#define pb push_back
#define F first
#define S second
#define ff first
#define endl "\n"
#define ss second
#define all(v) v.begin(), v.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int power(int x, unsigned int y, int p)
{
	int res = 1;
	x = x % p;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res % p;
}
int lcm(int a, int b)
{
	return a / __gcd(a, b) * b;
}

void solve()
{
	 int n;
	 cin>>n;
	 int a[n];
	 for (int i = 0; i < n;i++)
		 cin >> a[i];
	int i = 1, l = 0, ans = 0;
	 while(i<n){
		 if(a[i]<=a[i-1]){
			 i++;
		 }
		 else{
			 ans = max(ans, i - l - 1);
			 l = i;
			 i++;
		 }
	 }
	 ans = max(ans, i - l - 1);
	 cout << ans << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	tc = 1;
	//cin >> tc;
	while (tc--)
	{
		solve();
	}

	return 0;
}
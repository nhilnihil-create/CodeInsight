#include<bits/stdc++.h>
#define ll     long long int
#define mod    1000000007
#define io     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi      vector<int>
#define endl    "\n"
using namespace std;
void solve();
int main()
{
	io

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
//	/*is Single Test case?*/cin >> t;
	for (int i = 1; i <= t; i++)
	{	//cout<<"Case #"<<i<<": ";
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve()
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max({a * c, b * c, a * d, b * d});

}



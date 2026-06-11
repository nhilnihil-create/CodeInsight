#include <bits/stdc++.h>
using namespace std;
#define endl            "\n"
#define ff              first
#define ss              second
#define int             long long
#define pb              emplace_back
#define mp              make_pair
#define bs              binary_search
#define pqb             priority_queue<int>
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define ps(x,y)         fixed<<setprecision(y)<<x
#define test(x)         int x; cin>>x; while(x--)
#define pi              3.14159265358979323846
void c_p_c()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
// int pow(int a, int b, int c)
// {
// 	int res = 1;
// 	while (b > 0)
// 	{
// 		if (b % 2)
// 			res = (res * a) % c;
// 		a = (a * a) % c;
// 		b >>= 1;
// 	}
// 	return res;
// }
/*********************CODE BEGINS*******************/
void solve()
{
	int a,b;
	cin>>a>>b;
	cout<<a*b;
}
int32_t main()
{
	c_p_c();
	// test(x)
	solve();
}
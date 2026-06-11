#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define maxN 200005

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);

}



int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
#endif
	int n, x, t;
	cin >> n >> x >> t;
	cout << (((n + (x - 1)) / x)*t) << endl;
	return 0;
}
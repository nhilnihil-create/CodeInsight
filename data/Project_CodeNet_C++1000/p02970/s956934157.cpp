#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
int32_t main()
{


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d;
	cin >> n >> d;
	d = 2 * d;
	d++;

	cout << ceil(n * 1.0 / d);

}
#include<iostream>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n , k;
	cin >> n;
	cin >> k;
	//ll dis;
	//cout << max(n, k) << " " << min(n, k) << endl;
	//ll mn = min(n, k);
	//ll mx = max(n, k);
	ll temp = min(n%k, k-n%k);
	cout << temp << endl;
	//dis = abs(temp*mn - mx);
	//cout << dis << endl;
	return 0;
}

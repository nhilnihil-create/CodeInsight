#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	ll n, a, b;
	cin >> n >> a >> b;
	ll ans, rem;
	ans = n/(a+b) * a;
	rem = n%(a+b);
	ans += min(rem, a);
	cout << ans << "\n";
	return 0;
}

#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define mod 1000000007ll
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define db(x) cout << #x << " = " << x << '\n'
#define sep cout << "\n********************************************\n"
#define fast  ios_base::sync_with_stdio(false), cin.tie(NULL)
ll countpf(ll num)
{
	ll ans = 0;
	for (ll i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
		{
			ans ++;
			while (num % i == 0)
				num /= i;
		}
	}
	if (num > 1)
		ans ++;
	return ans + 1;
}
int main(int argc, char const *argv[])
{
    fast;
    ll a, b;
    cin >> a >> b;
    cout << countpf(__gcd(a, b)) << '\n';
    return 0;
}
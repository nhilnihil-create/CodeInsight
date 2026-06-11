#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> P;
#define INF 10000000000000
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
#define repN_1(i, n) for(ll i = 0; i < (ll)(n - 1); i++)
#define repM(i, n) for(ll i = (ll)(n - 1); i >= 0; i--)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main()
{
	ll n;
	cin >> n;
	ll c[3];
	c[0] = c[1] = c[2] = 0;

	vector<ll> a;

	rep(i, n)
	{
		ll t;
		cin >> t;
		auto it = find(a.begin(), a.end(), t);
		if (it == a.end())
		{
			a.push_back(t);
			if (a.size() > 3)
			{
				cout << "No" << endl;
				return 0;
			}
			c[a.size() - 1]++;
		}
		else
			c[distance(a.begin(), it)]++;

	}

	if (a.size() == 1 && a[0] == 0)
		cout << "Yes" << endl;
	else if (a.size() == 2 && ((c[0] / 2 == c[1] && a[1] == 0) || (c[1] / 2 == c[0] && a[0] == 0)))
		cout << "Yes" << endl;
	else if (c[0] == c[1] && c[1] == c[2] && ((a[0] ^ a[1]) == a[2]) && ((a[1] ^ a[2]) == a[0]) && ((a[0] ^ a[2]) == a[1]))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;


	return 0;
}
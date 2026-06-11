#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);

int ar[100];
int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> ar[i];

	ll money = 1000;
	for (int i = 1; i < n; ++i)
	{
		if (ar[i-1] < ar[i])
		{
			ll stock = money / ar[i-1];
			money += (ar[i] - ar[i-1]) * stock;
		}
	}
	cout << money << '\n';

	return 0;
}

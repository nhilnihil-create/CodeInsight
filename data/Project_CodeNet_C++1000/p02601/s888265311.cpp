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

int main()
{
	fastio;

	int a, b, c;
	int k;

	cin >> a >> b >> c;
	cin >> k;

	while (a >= b)
		b *= 2, k--;

	while (b >= c)
		c *= 2, k--;

	cout << (k < 0 ? "No\n" : "Yes\n");

	return 0;
}

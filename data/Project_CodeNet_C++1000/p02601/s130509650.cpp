#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef V<int> vi;
typedef V<ll> vll;
typedef V<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define prec(x) cout<<fixed<<setprecision(x)
#define f(i,a) for(int i = 0 ; i < a ; i++)
#define ff first
#define ss second
#define all(x) (x).begin() ,(x).end()

#define pb push_back
#define mp make_pair
#define numberofdigits(x) floor(log10(x)) + 1

ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

void solve()
{
	int a , b , c , k;
	cin >> a >> b >> c >> k;

	int cnt = 0;

	while (b <= a)
		b *= 2 , cnt++;
	if (cnt > k)
	{
		cout << "No\n";
		return;
	}

	while (c <= b)
		c *= 2 , cnt++;

	if (cnt <= k)
		cout << "Yes\n";
	else
		cout << "No\n";


}


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int t = 1;
	//cin >> t;

	while (t--)
	{
		solve();
	}

	return 0;
}




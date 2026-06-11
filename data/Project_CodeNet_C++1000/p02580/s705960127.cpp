#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long ll;
typedef unsigned long long ull;

typedef V<int> vi;
typedef V<ll> vll;
typedef V<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define f(i,a) for(int i = 0 ; i < a ; i++)
#define fll(i,a) for(ll i = 0 ; i < a ;i++)
#define forab(i,a,b) for(int i = a ; i < b ; i++)
#define prec(x) cout<<fixed<<setprecision(x)
#define ff first
#define ss second

#define pb push_back
#define mp make_pair
#define numberofdigits(x) floor(log10(x)) + 1

ll M = 1e7 + 7;

ll binpow(ll a, long long b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a);
		a = (a * a);
		b >>= 1;
	}
	return res;
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int H , W , M;
	cin >> H >> W >> M;

	set<pair<int, int>> target;

	ll row[H + 1] = {0LL} , col[W + 1] = {0LL};
	int R = 1, C = 1 , mxr = -1 , mxc = -1;

	for (int i = 0 ; i < M ; i++)
	{
		int h , w;
		cin >> h >> w;
		target.insert({h, w});

		row[h]++ , col[w]++;
		if (mxr < row[h])
		{
			mxr = row[h];
			R = h;
		}

		if (mxc < col[w])
		{
			mxc = col[w];
			C = w;
		}
	}

	ll ans = 0;

	for (int j = 1 ; j <= W ; j++)
	{
		if (mxc == col[j])
		{
			ll d = row[R] + col[j];

			if (target.count({R , j}) > 0)
				d--;
			ans = max(ans , d);

		}
	}

	for (int i = 1 ; i <= H ; i++)
	{
		if (mxr == row[i])
		{
			ll d = row[i] + col[C];
			if (target.count({i , C}) > 0)
				d--;
			ans = max(ans , d);
		}
	}

	cout << ans << "\n";

	return 0;
}




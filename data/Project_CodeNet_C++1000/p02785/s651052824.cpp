#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define MOD 1000000007
#define FormulaToConvertMicrosecondsToSeconds(duration) duration / 1e+6
#define _CRT_SECURE_NO_DEPRECATE
#define ll                    long long
#define nl                    '\n'                             // NL - sign of new line

#define upperString(str)      transform(str.begin(), str.end(), str.begin(), ::toupper); // make entire string uppercase
#define lowerString(str)      transform(str.begin(), str.end(), str.begin(), ::tolower); // make entire string lowercase

#define ps(x,y)               fixed << setprecision(y) << x     // usage: t=1.1234; cout << ps(t,4); // it means it will print 4 decimal places.

#define eb                    emplace_back
#define sortv(v)              sort(v.begin(), v.end());
#define rsortv(v)             sort(v.rbegin(), v.rend());
#define rev(v)		          reverse(v.begin(), v.end())       // reverse the vector

#define si                    set<int>

#define mii			          std::map <int,int>
#define multimii		      std::multimap <int,int>
#define mss			          map <string, string>
#define w(t)                  unsigned t; cin >> t; while(t--)
mt19937                       rng(chrono::steady_clock::now().time_since_epoch().count());

void solve();
//==================================

bool isPrime(int num) {
	if (num == 1) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

ll binarySearch(int a[], int l, int r, int x)
{
	while (l <= r)
	{
		int mid_index = l + (r - l) / 2;

		if (a[mid_index] == x)
			return mid_index;
		else if ( x > a[mid_index])
		{
			l = mid_index + 1;
		}
		else if ( x < a[mid_index])
		{
			r = mid_index - 1;
		}
	}
	return -1;
}

ll fast_power(ll base, ll power) {
	ll result = 1;
	while (power > 0) {

		// if( power % 2 == 1)
		if (power & 1) { // Can also use (power & 1) to make code even faster
			result = (result * base) % MOD;
		}
		base = (base * base) % MOD;

		// power /= 2
		power >>= 1; // Can also use power >>= 1; to make code even faster
	}
	return result;
}

//==================================
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//--------------------------------
	auto t1 = std::chrono::high_resolution_clock::now();

	//int t = 1;
	//cin >> t;
	//while (t--)
	//{

	solve();
	//}



	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

	cerr << "\n\nTime taken : " << FormulaToConvertMicrosecondsToSeconds(duration) << " secs" << nl;
	return 0;
}

void solve() //Task A. Double Cola!!! Two teams composing !
{

	unsigned ll n, s; cin >> n >> s;
	if (s >= n) {
		cout << 0; return;
	}
	else if (s == 0)
	{
		unsigned ll ans = 0;
		while (n--)
		{
			unsigned ll e; cin >> e;
			ans += e;
		}
		cout << ans;
	}
	else
	{
		vector<unsigned ll>v(n);
		unsigned ll ans = 0;
		for (ll i = 0; i < n; ++i)
		{
			cin >> v[i];
		}

		sortv(v);

		unsigned ll sum = 0;
		for (int i = 0; i < n - s; ++i)
		{
			sum += v[i];
		}
		cout << sum;
	}

} // !solve


/* TESTS:


*/
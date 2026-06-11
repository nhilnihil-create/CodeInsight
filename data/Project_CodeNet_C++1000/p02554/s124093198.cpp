/*
* @Author: Kabid
* @Date:   {{create_time}}
* @Last Modified by:   Kabid
* @Last Modified time: 2020-09-20 20:58:29
*/
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
#define ll long long
#define  in(x) scanf("%d",&x);
#define out(x) printf("%d",x);
#define  ins(x)  scanf("%s",x);
#define outs(x) printf("%s",x);
#define lin puts("");
#define _ putchar(' ');

int t;       //test cases
ll i, j;	 //iterators
ll n, k ,  q,  d, m, c, c1, c2, d1, x; //variables;
ll mx1 = LLONG_MIN, mx2 = LLONG_MIN, mx = LLONG_MIN, mn = LLONG_MAX;		// max min
char s[6], s1, s2;		// string
ll a [1000001], b [200001] ;
bool mox [1000001];	// array
map <int, int > mp;
vector <vector<ll>> vc;
vector <ll> v;
set <ll> st;
bool r;
ll p = 1000000007;
ll power(ll x, unsigned ll y, ll p)
{
	ll res = 1;     // Initialize result

	x = x % p; // Update x if it is more than or
	// equal to p

	if (x == 0) return 0; // In case x is divisible by p;

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * x) % p;

		// y must be even now
		y = y / 2; // y = y/2
		x = (x * x) % p;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cin >> t; q = t;
	t = 1;

	while (t--) {

		cin >> n;
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		/*if (n == 2) {
			cout << 2 << endl;
			continue;
		}*/
		//ll ans=power(10,n-2,p);
		ll ans = 1;
		ll ans2 = 1;
		ll ans3 = 1;
		for (i = 1; i <= n ; i++) {
			ans = ((ans ) * 10) % p;
			ans2 = (ans2 * 9) % p;
			ans3 = (ans3 * 8) % p;
		}
		//cout<<ans<<' '<<ans2<<' '<<ans3<<endl;

		cout << ((ans -2*ans2 +ans3)%p +p) %p<< endl;


		//cout<<mod;
	}


	return 0;

}
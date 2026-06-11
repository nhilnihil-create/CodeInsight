#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl '\n'
ll power(ll x, ll y, ll p)
{ 
    ll res = 1;  
    x = x % p;
    while (y > 0) { 
        if (y & 1) res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p;   
    } 
    return res; 
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n, k, C;
 	cin >> n >> k >> C;
 	string s;
 	cin >> s;   
	ll c = 0;
	vector <ll> v1;
	ll c2 = 0;
	while (c < n) {
		if (c2 == k) break;
		if (s[c] == 'x') c++;
		else {
			c2++;
			v1.pb(c);
			c += (C + 1);
		}
	} 	
	c = n - 1;
	c2 = 0;
	vector <ll> v2;
	while (c >= 0) {
		if (c2 == k) break;
		if (s[c] == 'x') c--;
		else {
			c2++;
			v2.pb(c);
			c -= (C + 1);
		}
	}
	reverse(all(v2));
	for (ll i = 0; i < k; i++) {
		if (v1[i] == v2[i]) {
			cout << v1[i] + 1 << endl;
		}
	}
 	return 0;
}
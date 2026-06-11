#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define pf push_front
#define PI acos(-1)
#define EPS 1e-5
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define forn(i, n) for(ll i=0;i<(ll)n;i++)
#define fi first
#define se second
 

int main() {
	ll n;
	cin >> n;
	ll mn = 1e12+10;
	for(int i = 1; i <= sqrt(n); i++) {
		if(n % i == 0)
			mn = min(mn, i+(n/i)-2);
	}
	cout << mn << endl;
	return 0;
}


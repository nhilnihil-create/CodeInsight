#include <bits/stdc++.h>
using namespace std;
#define FOR(ii, ss, ee) for(ll ii = (ss); ii <= (ll)(ee); ++ii)
#define DEC(ii, ss, ee) for(ll ii = (ss); ii >= (ll)(ee); --ii)
#define VALS(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define IAMSPEED ios_base::sync_with_stdio(false); cin.tie(0);
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define pf push_front
#define LLINF ((long long)1e18)
#define INF 1234567890ll
#define EPS (1e-7)    //0.0000001 the value
#define PI (acos((ld)-1.0))
#define ll long long int 
#define ld long double
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define f first
#define s second
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
const int MOD = 1e9 + 7;
multiset <ll> ms;
vector <ll> v;
int main()
{
	IAMSPEED
	ll n; cin >> n;
	FOR (i, 1, pow(2, n)) {
		ll x; cin >> x;
		ms.insert(x);
	}
	v.pb(*prev(ms.end()));
	ms.erase(prev(ms.end()));
	FOR (i, 1, n) {
		vector <ll> newv;
		for (auto it : v) { // find the largest one that is smaller than the current slime
			if (ms.lower_bound(it) != ms.begin()) {
				newv.push_back(*prev(ms.lower_bound(it)));
				ms.erase(prev(ms.lower_bound(it)));
				//VALS(it, *prev(newv.end()));
			}
		}
		for (auto it : newv) v.pb(it);
	}
	if (v.size() == pow(2, n)) cout << "Yes";
	else cout << "No";
	return 0;
}

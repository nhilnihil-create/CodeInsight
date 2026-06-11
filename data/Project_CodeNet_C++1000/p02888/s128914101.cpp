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
	int n;
	cin >> n;
	vector<int> l(n);
	forn(i, n) cin >> l[i];
	sort(all(l));
	int cnt = 0;
	for(int i = n-1; i >= 0; i--) {
		for(int j = i-1; j >= 0; j--) {
			auto ind = lower_bound(all(l), l[i]+l[j]);
			ll num = distance(ind, l.end());
			cnt += (n-1-i) - num;
		}
	}
	cout << cnt << endl;

	return 0;
}


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
	int n, k, r, s, p;
	cin >> n >> k >> r >> s >> p;
	string t;
	cin >> t;
	vector<int> mod(k, 0);
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		if(t[i] == 'r') {
			if(mod[i%k] == 1) {
				mod[i%k] = 0;
				continue;
			} else {
				sum += p;
			}
			mod[i%k] = 1;
		} else if(t[i] == 's') {
			if(mod[i%k] == 2) {
				mod[i%k] = 0;
				continue;
			} else {
				sum += r;
			}
			mod[i%k] = 2;
		} else {
			if(mod[i%k] == 3) {
				mod[i%k] = 0;
				continue;
			} else {
				sum += s;
			}
			mod[i%k] = 3;
		}
	}
	cout << sum << endl;
	return 0;
}


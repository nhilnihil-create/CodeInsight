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
	string s;
	cin >> s;
	int q;
	cin >> q;
	bool reversed = false;
	deque<char> d(all(s));
	while(q--) {
		int t;
		cin >> t;
		if(t==1)
			reversed = !reversed;
		else {
			int f;
			cin >> f;
			char ch;
			cin >> ch;
			if(f == 1) {
				if(reversed)
					d.pb(ch);
				else d.pf(ch);
			} else {
				if(reversed)
					d.pf(ch);
				else d.pb(ch);
			}
		}
	}
	string res(d.begin(), d.end());
	if(reversed) reverse(all(res));
	cout << res << endl;

	return 0;
}


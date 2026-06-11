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
	int n, m;
	cin >> n >> m;
	int corr = 0, pena = 0;
	map<int, int> ma;
	vector<int> ac(n);
	forn(i, m) {
		int p;
		cin >> p;
		string s;
		cin >> s;
		if(!ac[p-1]) {
			if(s == "WA") ma[p]++;
			else {
				corr++;
				pena += ma[p];
				ac[p-1] = true;
			}
		}
	}
	cout << corr << " " << pena << endl;
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
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
	int n = sz(s);
	bool ok = true;
	for(int i = 0; i < n/2; i++) {
		if(s[i]!=s[n-i-1]) {
			ok = false;
			break;
		}
	}
	for(int i = 0; i < (n-1)/4; i++) {
		if(s[i] != s[(n-1)/2-i-1]) {
			ok = false;
			break;
		}
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}


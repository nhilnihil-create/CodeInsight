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
	vector<int> a(n, -1);
	forn(i, m) {
		int s, c;
		cin >> s >> c;
		if(a[s-1] != -1 && a[s-1] != c) {
			cout << -1 << endl;
			return 0;
		}
		a[s-1] = c;
	}
	if((a[0] == 0 && n == 1 && a.size() == 1)|| a[0] == -1 && n==1 &&a.size() == 1){
		cout << 0 << endl;
		return 0;
	}

	if(a[0] == 0) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> res(n);
	if(a[0] == -1)
		res[0] = 1;
	else res[0] = a[0];
	for(int i = 1; i < n; i++) {
		if(a[i] == -1)
			res[i] = 0;
		else res[i] = a[i];
	}
	forn(i, n) cout << res[i];
	cout << endl;
		
	return 0;
}


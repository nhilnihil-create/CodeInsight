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
	vector<vector<int>> a(3, vector<int>(3));
	forn(i, 3) forn(j, 3) cin >> a[i][j];
	int n;
	cin >> n;
	vector<int> b(n);
	vector<vector<bool>> u(3, vector<bool>(3));
	forn(i, n){
	   	cin >> b[i];
		forn(j, 3) forn(k, 3)
			if(a[j][k] == b[i])
				u[j][k] = true;
	}
	bool ok = false;
	forn(i, 3) {
		if(u[i][0] && u[i][1] && u[i][2]) {
			ok = true;
			break;
		}
	}
	forn(i, 3) {
		if(u[0][i] && u[1][i] && u[2][i]) {
			ok = true;
			break;
		}
	}
	if(u[0][0]&&u[1][1]&&u[2][2])
		ok = true;
	if(u[0][2]&&u[1][1]&&u[2][0])
		ok = true;
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}


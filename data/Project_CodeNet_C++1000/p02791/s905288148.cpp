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
	vector<int> a(n);
	forn(i, n) cin >> a[i];
	vector<int> mn(n);
	mn[0] = a[0];
	for(int i = 1; i < n; i++) {
		mn[i] = min(mn[i-1], a[i]);
	}
	int cnt = 1;
	for(int i = 1; i < n; i++) {
		if(a[i] <= mn[i-1])
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}


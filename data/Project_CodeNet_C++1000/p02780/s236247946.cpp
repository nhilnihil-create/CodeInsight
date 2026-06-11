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
	int n, k;
	cin >> n >> k;
	vector<double> p(n);
	forn(i, n) cin >> p[i];
	forn(i, n) p[i] = (p[i]+1)/2.0;
	double sum = 0;
	for(int i = 0; i < k; i++)
		sum += p[i];
	double mx = sum;
	for(int i = k; i < n; i++) {
		sum -= p[i-k];
		sum += p[i];
		mx = max(mx, sum);	
	}
	cout << fixed << setprecision(8) << mx << endl;
	return 0;
}


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
	int a, b, h, m;
	cin >> a >> b >> h >> m;
	double degh =(h +m/60.0)* 30;
	double degm = m * 6;
	double diff = abs(degh - degm);
	double deg = min(diff, 360-diff);
	double res = sqrt(a*a + b*b - 2*a*b*cos(PI*deg / 180));
	cout << fixed << setprecision(11) << res << endl;
	return 0;
}


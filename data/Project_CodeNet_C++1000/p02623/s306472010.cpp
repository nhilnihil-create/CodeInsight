#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define F first
#define S second
#define ld long double
#define rep(i,a,n) for (ll i = (a) ; i < (n); ++i)
#define vi vector<ll>
#define all(v) (v).begin(),(v).end()
#define M_PI 3.14159265358979323846
const ll MOD = 1e9 + 7;
const ll INF = 1e18L + 5;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n), b(m);
    rep(i,0,n) cin>>a[i];
    rep(i,0,m) cin>>b[i];

	int lena = 0;
	rep(i, 0, n) {
		if ( i != 0)
			a[i] += a[i - 1];
        //cout<<a[i]<<" ";
		if ( a[i] > k) {
			lena = i + 1;
			break;
		}
	}
	//cout<<endl;
	//cout<<lena<<endl;

	int lenb = 0;
	rep(i, 0, m) {
		if ( i != 0)
			b[i] += b[i - 1];

		if ( b[i] > k) {
			lenb = i + 1;
			break;
		}
	}
	if ( lena == 0 ) lena = n + 1;
	if ( lenb == 0 ) lenb = m + 1;

    //cout<<lena<<' '<<lenb<<endl;
	ll ans = max(lena, lenb) - 1, ca = lena-1;

	int i = lena - 2, j = 0;

	while ( i >= 0 && j < lenb - 1 ) {

		if ( a[i] + b[j] <= k ) {
			j++;
			ca++;
		}
		else {
			i--;
			ca--;
		}
		ans = max(ans, ca);
	}

	cout << ans << endl;

}


int main() {

	int t = 1;

	//cin >> t;
	ll k = 1;
	while (t--) {
		//cout << "Case #" << k++ << ": ";
		solve();
	}
	return 0;
}

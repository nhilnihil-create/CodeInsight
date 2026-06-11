#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll lg=31;
const ll N=1e5+5;
const ll INF=3e18;
const ll mod=1e9+7;
const double PI = 3.14159265358979323846;

#define f first
#define s second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repp(i, a, b) for(int i = a; i > (b); --i)
#define sz(x) (int)(x).size()
#define pb push_back
#define GCD(a,b) __gcd((a),(b))
#define all(v) v.begin(),v.end()
#define LCM(a,b) ((a)*(b))/GCD((a),(b))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
	FASTIO;
	ld d, t, s;
	cin >> d >> t >> s;
	ld tt = d / s;
	if (tt <= t) {
	    cout << "Yes" << endl;
	}else {
	    cout << "No" << endl;
	}
	return 0;
}
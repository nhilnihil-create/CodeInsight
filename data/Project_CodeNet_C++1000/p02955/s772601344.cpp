#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int INF = 987654321;
const int MOD = (int)1e9+7;
//const long double PI = (acos(-1));
//const long double EPS = 0.0000000001;

ll n,k;
vl a;

bool can(int cand) {
	//cout << cand << endl;
	vl na = a;
	ll nk = 0;

	rep(i,0,n) {
		na[i] %= cand;
	}

	sort(all(na));

	/*rep(i,0,n) {
		cout << na[i] << ' ';
	}
	cout << endl;*/

	int i = 0;
	int j = n-1;
	while(i < j) {
		if(na[i]%cand == 0) {
			i++;
			continue;
		} else if(na[j] % cand == 0) {
			j--;
			continue;
		}

		int x = na[i];
		int y = abs(cand-na[j]);
		if(x == y) {
			nk += x;
			na[i] -= x;
			na[j] += y;
			i++;
			j--;
		} else if (x < y) {
			nk += x;
			na[i] -= x;
			na[j] += x;
			i++;
		} else {
			nk += y;
			na[i] -= y;
			na[j] += y;
			j--;
		}
	}

	/*rep(i,0,n) {
		cout << na[i] << ' ';
	}
	cout << endl;
	cout << nk << endl;*/
	if(na[i] % cand > 0 || na[j] % cand > 0) {
		return false;
	}
	if (nk <= k) {
		return true;
	} else {
		return false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n >> k;
	a.resize(n);
	ll A = 0;
	rep(i,0,n) {
		cin >> a[i];
		A += a[i];
	}
	ll limit = sqrt(A);

	ll ret = 0;
	for(int i=1; i<=limit; ++i) {
		if(A%i) {
			continue;
		}
		if(can(A/i)) {
			ret = A/i;
			break;
		}
		if(can(i)) {
			ret = i;
		}
	}
	cout << ret << endl;
	return 0;
}

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
 
int N;
int A[20];
int x[20][20];
int y[20][20];

int counter(int x) {
	if(x == 0) return 0;
	return counter(x >> 1) + (x & 1);
}

void solve() {
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
		for(int j = 1; j <= A[i]; j++) {
			cin >> x[i][j] >> y[i][j];
		}
	}
	int ans = 0;
	for(int bits = 1; bits < (1 << N); bits++) {
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(!(bits & (1 << (i-1)))) continue;
			for(int j = 1; j <= A[i]; j++)
				if(((bits >> (x[i][j]-1)) & 1) ^ y[i][j]) ok = false;
		}
		if(ok) ans = max(ans, counter(bits));
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}


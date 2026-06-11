#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(i,j,n) for(ll i = (ll)(j); i < (ll)(n); i++)
#define mrep(i,n) for (ll i = (ll)(n-1); i > 0; i--)
#define be(v) (v).begin(), (v).end()
#define scout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	int n,k,q; cin >> n >> k >> q;
	vint point(n+1,0);
	int no=k-q;
	rep(i,q) {
		int a; cin >> a;
		point[a]++;
	}
	for(int i=1;i<=n;i++) {
		if(point[i]+no>0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
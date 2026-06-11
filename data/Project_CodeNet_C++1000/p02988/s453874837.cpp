#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i,j,n) for(int i = (int)(j); i < (int)(n); i++)
#define mrep(i,n) for (int i = (int)(n); i > 0; i--)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20)
ll INF = 1LL << 60;
ll mod = 1e9 + 7;
ll modn = 998244353;

int main() {
	int n; cin >> n;
	vint p(n);
	rep(i,n) cin >> p[i];
	int ans = 0;
	for(int i=1; i<n-1;i++) {
		if((p[i - 1] < p[i]) && (p[i] < p[i + 1])) ans++;
		else if((p[i - 1] > p[i]) && (p[i] > p[i + 1])) ans++;
	}
	cout << ans << endl;
}
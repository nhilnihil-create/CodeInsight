#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n;
	cin >> n;
	vector<ll> v(n);
	rep(i,n) cin >> v[i];
	rep(i,n) {
		if (v[i] == 0) {
			cout << 0 << endl;
			return 0;
		}
	}
	ll t = v[0];
	rep(i,n-1) {
		if (v[i+1] > 1000000000000000000 / t) {
			cout << -1 << endl;
			return 0;
		}
		t *= v[i+1];
	}
	cout << t << endl;
}
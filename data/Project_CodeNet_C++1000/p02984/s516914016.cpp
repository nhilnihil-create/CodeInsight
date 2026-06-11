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
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	vector<ll> b(n,0);
	rep(i,n) {
		if (i % 2 == 0) b[0] += a[i];
		else b[0] -= a[i];
	}
	rep(i,n-1) {
		b[i+1] = 2 * a[i] - b[i];
	}
	rep(i,n) {
		if (i != 0) cout << " ";
		cout << b[i];
	}
	cout << endl;
}
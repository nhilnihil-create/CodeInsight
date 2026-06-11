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
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	int l = 0;
	int r = INF + 1;
	while (l + 1 < r) {
		int x = (l + r) / 2;
		int t = 0;
		for (int p: v) {
			if (p <= x) continue;
			t += p/x;
		}
		if (t <= k) r = x;
		else l = x;
	}
	cout << r << endl;
}
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
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

int f(int n) {
	if (n <= 9) return 1;
	else return 1 + f(n / 10);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> s(m), c(m);
	rep(i,m) cin >> s[i] >> c[i];
	for (int i = 0; i < 1000; i++) {
		int keta = f(i);
		if (keta != n) continue;
		string t = to_string(i);
		bool b = true;
		rep(j,m) {
			if ((int)(t[s[j] - 1] - '0') != c[j]) b = false;
		}
		if (b) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
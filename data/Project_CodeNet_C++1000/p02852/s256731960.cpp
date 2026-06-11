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
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	reverse(ALL(s));

	vector<int> ans;
	for (int i = 0; i < n;) {
		int ni = min(n, i + m);
		while (s[ni] == '1') ni--;
		if (ni == i) {
			cout << -1 << endl;
			return 0;
		} else {
			ans.push_back(ni - i);
			i = ni;
		}
	}
	reverse(ALL(ans));
	rep(i,ans.size()) {
		if (i != 0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
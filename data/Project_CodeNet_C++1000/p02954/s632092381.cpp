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
	string s;
	cin >> s;
	int n = s.size();
	vector<int> ans(n);
	for (int i = 0; i < n;) {
		int l = 0;
		int r = 0;
		while (i < n && s[i] == 'R') {
			r++;
			i++;
		}
		int p1 = i-1;
		int p2 = i;
		while (i < n && s[i] == 'L') {
			l++;
			i++;
		}
		ans[p1] = dup(r, 2) + l / 2;
		ans[p2] = r / 2 + dup(l, 2);
	}

	rep(i,n) cout << ans[i] << " ";
	cout << endl;
}
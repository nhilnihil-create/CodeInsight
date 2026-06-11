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
	rep(i,k) {
		int d;
		cin >> d;
		rep(j,d) {
			int a;
			cin >> a;
			a--;
			v[a]++;
		}
	}
	int ans = 0;
	rep(i,n) if (!v[i]) ans++;
	cout << ans << endl;
}
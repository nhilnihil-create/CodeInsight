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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	while (true) {
		c -= b;
		if (c <= 0) {
			cout << "Yes" << endl;
			return 0;
		}
		a -= d;
		if (a <= 0) {
			cout << "No" << endl;
			return 0;
		}
	}
}
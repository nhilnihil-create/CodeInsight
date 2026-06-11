#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

#define rad_to_deg(rad) (((rad)/2/PI)*360)

void solve() {
	double a, b, x;
	cin >> a >> b >> x;
	double res;
	if (x / a == a * b / 2) {
		res = 45;
	} else if (x / a < a * b / 2) {
		double s = x / a;
		double l = 2.0 * s / b;
		res = rad_to_deg(atan(b / l));
	} else {
		double s = a * b - (x / a);
		double r = 2.0 * s / a;
		res = rad_to_deg(atan(r / a));
		
	}
	printf("%.10f", res);
}

int main() {
	solve();
	return 0;
}
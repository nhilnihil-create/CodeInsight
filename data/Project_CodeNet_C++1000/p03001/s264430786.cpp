#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define rep_sn(i,s,n) for(int i=(s);i<(s)+(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {
	
	int w, h, x, y;
	cin >> w >> h >> x >> y;
	cout << fixed << setprecision(10);
	cout << (long double)h * w / 2 << " ";
	bool center = false;
	if (2 * x == w && 2 * y == h)center = true;
	cout << (center ? 1 : 0) << endl;

}
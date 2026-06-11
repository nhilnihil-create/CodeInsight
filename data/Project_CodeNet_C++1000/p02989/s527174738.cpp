#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000LL;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	vi d(n);
	rep(i, n)cin >> d[i];
	sort(all(d));
	cout << d[n / 2] - d[n / 2 - 1] << endl;

}
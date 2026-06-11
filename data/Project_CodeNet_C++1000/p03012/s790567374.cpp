#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%d\n",n)
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	int n;
	cin >> n;
	vector<int> w(n);
	rep(i, n) cin >> w[i];

	int sum = 0;
	rep(i, n) sum += w[i];

	int sub = 0;
	int ans = 10010001;
	rep(i, n) {
		sub += w[i];
		ans = min(abs(2 * sub - sum), ans);
		//pf(abs(2 * sub - sum));
	}
	pf(ans);

	return 0;
}
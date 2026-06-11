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
#define pff(a,b) printf("%d  %d\n",a,b);
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	int n, d;
	cin >> n >> d;
	int x[10][10] = { 0 };
	rep(i, n)rep(j, d) cin >> x[i][j];

	int cnt = 0;
	rep(i1, n) {
		for(int i2=i1+1;i2<n;i2++){
			double dis = 0;
			rep(j1, d) {
				dis += (x[i1][j1] - x[i2][j1])*(x[i1][j1] - x[i2][j1]);
			}
			int diss = sqrt(dis);
			if (diss*diss == dis) cnt++;
		}
	}
	pf(cnt);

	return 0;
}
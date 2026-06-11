#include <iostream>
#include<iomanip>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#define INF long long int(1e18+1)
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;


int main() 
{
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	rep(i, 0, n)cin >> a[i];

	long int tot = 0;
	int totfirst = 0;
	rep(i, 0, k)tot += a[i];
	long int max = tot;
	rep(i, k, n) {
		tot = tot + a[i] - a[i - k];
		if (max < tot) {
			max = tot;
			totfirst = i - k + 1;
		}
	}
	double ans = 0;
	rep(i, totfirst, totfirst + k) {
		ans+=static_cast<double>((a[i]+ 1) / 2.0);
	}
	cout << fixed << setprecision(7) << ans << endl;
}



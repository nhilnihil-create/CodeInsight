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
#include<ctime>
#include<cstdlib>
#define INF 1001001001001001001
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>>a(n);
	rep(i, 0, n)cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end());
	double ans = 0.0;
	do {
		rep(i, 1, n)ans += sqrt((a[i].first - a[i - 1].first) * (a[i].first - a[i - 1].first) + (a[i].second - a[i - 1].second) * (a[i].second - a[i - 1].second));
		
	} while (next_permutation(a.begin(), a.end()));
	rep(i, 1, n + 1)ans /= i;
	cout << fixed << setprecision(6) << ans << endl;
}
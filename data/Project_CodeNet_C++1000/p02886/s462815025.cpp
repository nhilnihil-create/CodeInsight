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
	vector<int>a(n);
	rep(i, 0, n)cin >> a[i];
	long long int ans = 0;
	rep(i, 0, n)rep(j, i, n) {
		if (i == j)continue;
		ans += a[i] * a[j];
	}
	cout << ans << endl;
}

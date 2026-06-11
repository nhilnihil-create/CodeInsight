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
	vector<long long int >h(n);
	rep(i, 0, n)cin >> h[i];
	long long int ans = 0;
	sort(h.begin(), h.end());
	if (k < n) {
		rep(i, 0, n - k)
			ans += h[i];
	}
	cout << ans << endl;

}
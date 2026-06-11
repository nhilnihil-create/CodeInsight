#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint x[55], y[55];
map<P, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			mp[P(x[i]-x[j], y[i]-y[j])]++;
		}
	}
	
	llint ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++)
	{
		ans = max(ans, it->second);
	}
	ans = n - ans;
	cout << ans << endl;
	
	return 0;
}
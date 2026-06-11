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
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint n, k;
llint a[200005], s[200005];
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i], s[i] %= k;
	for(int i = 1; i <= n; i++) s[i] += k-i%k, s[i] %= k;
	
	//for(int i = 0; i <= n; i++) cout << s[i] << " "; cout << endl;
	
	llint ans = 0;
	for(int i = 0; i <= n; i++){
		ans += mp[s[i]];
		mp[s[i]]++;
		if(i-(k-1) >= 0) mp[s[i-(k-1)]]--;
	}
	cout << ans << endl;
	
	return 0;
}
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
#define printP(x) "(" << (x).first << ", " << (x).second << ")"
#define mod 998244353
using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

llint n, m, v, p;
llint a[100005];

bool check(llint x)
{
	llint sum = 0, ub = a[x]+m;
	if(ub < a[p]) return false;
	if(v <= p) return true;
	
	for(int i = p; i <= n; i++){
		if(i == x) continue;
		sum += min(m, ub-a[i]);
	}
	return sum/(v-p) >= m;
}

int main(void)
{
	cin >> n >> m >> v >> p;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	
	llint ub = n+1, lb = p, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	cout << lb << endl;
	
	return 0;
}

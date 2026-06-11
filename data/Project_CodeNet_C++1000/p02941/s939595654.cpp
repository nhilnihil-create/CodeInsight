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
//#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define printP(x) "(" << (x).first << ", " << (x).second << ")"
#define mod 1000000007
using namespace std;
typedef pair<int, int> P;

llint n;
llint a[200005], b[200005];
queue<llint> Q;

llint get(llint p)
{
	if(b[p] <= a[p] && b[p] <= b[(p-1+n)%n]+b[(p+1)%n]) return 0;
	llint s = b[(p-1+n)%n]+b[(p+1)%n], m = max(b[(p-1+n)%n], b[(p+1)%n]);
	return min((b[p]-a[p])/s, (b[p]-m+s-1)/s);
}

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	
	for(int i = 0; i < n; i++){
		if(get(i) > 0) Q.push(i);
	}
	
	llint ans = 0;
	while(Q.size()){
		llint p = Q.front(); Q.pop();
		llint x = get(p), s = b[(p-1+n)%n]+b[(p+1)%n];
		ans += x, b[p] -= x * s;
		if(get((p+1)%n) > 0) Q.push((p+1)%n);
		if(get((p+n-1)%n) > 0) Q.push((p+n-1)%n);
	}
	for(int i = 0; i < n; i++){
		if(a[i] != b[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
	
	return 0;
}

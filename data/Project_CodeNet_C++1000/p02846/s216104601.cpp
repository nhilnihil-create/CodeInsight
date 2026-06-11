#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const long long INFL = 2e18;
const int MOD = 1000000007;
int main(){
	int t1,t2;
	cin >> t1 >> t2;
	ll a1,a2,b1,b2;
	cin >> a1 >> a2 >> b1 >> b2;

	if(t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2){
		cout << "infinity" << endl;
		return 0;
	}

	if(t1 * a1 + t2 * a2 < t1 * b1 + t2 * b2){
		swap(a1,b1);
		swap(a2,b2);
	}


	ll sub = t1 * a1 + t2 * a2 - t1 * b1 - t2 * b2;

	ll ans = 0;
	if(b1 > a1){
		ans += (t1 * (b1 - a1)) / sub;
	}

	if(b2 - a2 > 0){
		ll l = t1 * (b2 - a2) - t1 * (a1 - a2 - b1 + b2);
		ll r = (t1 + t2) * (b2 - a2) - t1 * (a1 - a2 - b1 + b2);

		if(l < 0){
			l = - (- l + sub - 1) / sub;
		}
		else l /= sub;

		if(r < 0){
			r = - (- r + sub - 1) / sub;
		}
		else r = (r + sub - 1) / sub - 1;

		if(r >= 0)ans += r - max(0LL,l) + 1;
	}
	else{
		ll r = t1 * (b2 - a2) - t1 * (a1 - a2 - b1 + b2);
		ll l = (t1 + t2) * (b2 - a2) - t1 * (a1 - a2 - b1 + b2);

		if(l < 0){
			l = - (- l + sub - 1) / sub;
		}
		else l /= sub;

		if(r < 0){
			r = - (- r + sub - 1) / sub;
		}
		else r = (r + sub - 1) / sub - 1;

		if(r >= 0)ans += r - max(0LL,l) + 1;
	}
	cout << ans << endl;
}

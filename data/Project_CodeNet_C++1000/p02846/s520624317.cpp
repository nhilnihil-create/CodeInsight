#include <iostream> // cin, cout, cerr
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota
#include <cstdio> // printf, scanf
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <iomanip> // cout<<setprecision(n)
#include <functional> // function<void(int)>

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define ENDL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int t1,t2;
	std::cin >> t1 >> t2;
	int a1,a2,b1,b2;
	std::cin >> a1 >> a2 >> b1 >> b2;
	int top = (a1-b1)*t1;
	int bottom = top + (a2-b2)*t2;
	if(bottom==0) {
		print("infinity");
		return 0;
	}
	if((top>0&&bottom>0) || (top<0&&bottom<0)) {
		print(0);
		return 0;
	}
	if(top<0)top*=-1;
	if(bottom<0)bottom*=-1;
	int count = 2*(top/bottom)+1;
	if(top%bottom==0) count--;
	print(count);
	return 0;
}

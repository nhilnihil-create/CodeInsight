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
#include <cmath>
#include <cassert>
#include <bitset>

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define EL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	int xx=0;
	int yy=0;
	rep(i,n) {
		if(s[i]=='2' && i==(i&(n-1)) ) xx^=1;
		if(s[i]=='2')yy=1;
	}
	if(xx==1) {
		print(1);
		return 0;
	}
	if(yy) {
		print(0);
		return 0;
	}
	int xxx=0;
	rep(i,n) {
		if(s[i]=='3' && i==(i&(n-1)) ) xxx^=1;
	}
	if(xxx) print(2);
	else print(0);
	return 0;
}

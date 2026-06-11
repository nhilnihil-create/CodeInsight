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
	int k,q;
	std::cin >> k >> q;
	std::vector<int> d(k);
	rep(i,k) std::cin >> d[i];
	rep(qq,q) {
		int n,x,m;
		std::cin >> n >> x >> m;
		n--;
		int zeros = 0;
		int sum = x%m;
		int xx = 0;
		rep(i,k) {
			xx+=d[i]%m;
			if(d[i]%m==0) zeros++;
		}
		sum+=xx*(n/k);
		zeros*=(n/k);
		int lastzero = false;
		rep(i,n%k) {
			sum+=d[i]%m;
			if(d[i]%m==0) zeros++;
		}
		print(std::max(n-sum/m-zeros,0ll));
	}
	return 0;
}

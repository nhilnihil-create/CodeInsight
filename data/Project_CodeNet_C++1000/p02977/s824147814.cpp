#include <iostream> // cin, cout, cerr, clog
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota, accumulate, inner_product
#include <cstdio> // printf, scanf
#include <climits> // INT_MIN, LLONG_MIN
#include <cmath> // long, trig, pow
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <stack> // stack
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <unordered_map> // hashed by keys
#include <unordered_set> // hashed by keys
#include <iomanip> // cout<<setprecision(n)
#include <functional> // std::function<void(int)>

#define rep(i,n) for(int i = 0; i < n; i++)
#define ENDL "\n"
#define print(i) std::cout << (i) << "\n"

#define int long long // at least int64 > 9*10^18
#define all(v) v.begin(), v.end()

signed main() {
	int n;
	std::cin >> n;
	int l = 1;
	for(;l<=n;l*=2) {
		if(n==l) {
			print("No");
			return 0;
		}
	}
	l/=2;

	print("Yes");
	for(int i=1;i<3;i++) {
		std::cout << i << ' ' << i+1 << ENDL;
		std::cout << n+i << ' ' << n+i+1 << ENDL;
	}
	std::cout << 1 << ' ' << n+3 << ENDL;
	for(int i=1;4+i<=n;i+=2) {
		std::cout << 3+i << ' ' << 1 << ENDL;
		std::cout << 4+i << ' ' << 3+i << ENDL;
		std::cout << 3+n+i << ' ' << 4+n+i << ENDL;
		std::cout << 1 << ' ' << 4+n+i << ENDL;
	}
	if(n%2==0) {
		std::cout << n << ' ' << l << ENDL;
		std::cout << 2*n << ' ' << n+(l^1^n) << ENDL;
	}
	return 0;
}

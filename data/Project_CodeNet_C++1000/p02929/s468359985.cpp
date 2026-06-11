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

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
int pow(int v,int k){int r(1),t(v);while(k){if(k&1)r*=t;t*=t;k>>=1;} return r;}

const int MOD = 1e9+7;

signed main() {
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0);

	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;

	if(s[0]=='W') {
		print(0);
		return 0;
	}

	// 0=L, 1=R
	std::vector<int> side(2*n);
	side[0]=0;
	rep(i,2*n-1) {
		if(s[i]==s[i+1]) side[i+1]=(side[i]+1)%2;
		else side[i+1]=side[i];
	}


	int count = 1;
	int Lcount = 0;
	int Rcount = 0;
	for(auto i:side) {
		if(i==1) count=count*(Lcount-Rcount)%MOD;
		if(i==0) Lcount++;
		else Rcount++;
	}

	if(Lcount!=Rcount) {
		print(0);
		return 0;
	}

	for(int i=1;i<=n;i++) count=count*i%MOD;

	print(count);

	return 0;
}

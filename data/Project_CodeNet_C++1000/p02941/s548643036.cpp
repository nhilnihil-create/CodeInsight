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

int mod(int x, int m) {
	return (x%m+m)%m;
}

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n),b(n);
	rep(i,n) std::cin >> a[i];
	rep(i,n) std::cin >> b[i];
	// b -> a
	std::priority_queue<std::pair<int,int> > que;
	rep(i,n) if(a[i]<b[i]) que.emplace(b[i],i);
	int count = 0;
	while(!que.empty()) {
		debug(a,b);
		auto x=que.top();que.pop();
		int xx=x.first;int i=x.second;
		int yy=b[mod(i+1,n)]+b[mod(i-1,n)];
		debug(xx,yy,i);
		if(xx<yy) {
			continue;
		}
		if(b[i]==a[i]) continue;
		if(xx<a[i]) {
			print(-1);
			return 0;
		}
		if(a[i]>yy && (xx-a[i])%yy==0) {
			b[i]=a[i];
			count+=(xx-a[i])/yy;
		} else {
			count+=(xx-1)/yy;
			xx-=((xx-1)/yy)*yy;
			if(xx<a[i]) {
				print(-1);
				return 0;
			}
			b[i]=xx;
			que.emplace(b[i],i);
		}
	}
	rep(i,n) if(a[i]!=b[i]) {
		print(-1);
		return 0;
	}
	print(count);

	return 0;
}

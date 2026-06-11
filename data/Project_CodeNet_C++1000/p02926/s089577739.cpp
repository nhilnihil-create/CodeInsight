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
#define print(i) std::cout << std::setprecision(16) << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

int gcd(int a, int b) {
  if (b==0) return a;
  return gcd(b,a%b);
}

inline int sign(int a) {
	if(a>0) return 1;
	if(a<0) return -1;
	return 0;
}

signed main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int,int> > vec;
	rep(i,n) {
		int x,y;
		std::cin >> x >> y;
		bool cont = true;
		for(auto& v:vec) {
			if(sign(v.first)*sign(x)<0 || sign(v.second)*sign(y)<0) continue;
			if(v.first==0 && x!=0) continue;
			if(v.first!=0 && x==0) continue;
			if(v.second==0 && y!=0) continue;
			if(v.second!=0 && y==0) continue;
			if(x==0&&y==0) {
				cont=false;
				break;
			}
			if(v.first==0 && x==0 && y>0 && v.second>0) goto here;
			if(v.first==0 && x==0 && y<0 && v.second<0) goto here;
			if(v.first>0 && x>0 && y==0 && v.second==0) goto here;
			if(v.first<0 && x<0 && y==0 && v.second==0) goto here;
			if(v.first==0 && x==0 && y<0 && v.second>0) continue;
			if(v.first==0 && x==0 && y>0 && v.second<0) continue;
			if(v.first<0 && x>0 && y==0 && v.second==0) continue;
			if(v.first>0 && x<0 && y==0 && v.second==0) continue;
			if(std::abs(x)*std::abs(v.second)==std::abs(y)*std::abs(v.first)) {
here:
				v.first+=x;
				v.second+=y;
				cont = false;
				break;
			}
		}
		if(x==0&&y==0) cont = false;
		if(cont) vec.emplace_back(x,y);
	}
	
	n=vec.size();
	if(n==0) {
		print(0);
		return 0;
	}
	std::vector<std::vector<int> > dot(n, std::vector<int>(n,0));
	rep(i,n) rep(j,n) {
		dot[i][j] = vec[i].first*vec[j].first + vec[i].second*vec[j].second;
	}
	std::vector<std::vector<int> > d(n, std::vector<int>(n,0));
	rep(i,n) rep(j,n) {
		d[i][j] = (-vec[i].second)*vec[j].first + vec[i].first*vec[j].second;
	}

	long double max = 0;
	rep(i,n) {
		int sumx1 = 0;
		int sumy1 = 0;
		int sumx2 = 0;
		int sumy2 = 0;
		std::vector<int> used(n,false);
		rep(j,n) {
			if(i==j) {
				continue;
			}
			if(d[i][j]>=0) {
				sumx1+=vec[j].first;
				sumy1+=vec[j].second;
				used[j] = true;
			}
		}
		rep(j,n) {
			if(!used[j]) {
				sumx2+=vec[j].first;
				sumy2+=vec[j].second;
			}
		}
		int zumx1 = 0;
		int zumy1 = 0;
		int zumx2 = 0;
		int zumy2 = 0;
		std::vector<int> used2(n,false);
		rep(j,n) {
			if(i==j) {
				continue;
			}
			if(d[i][j]<=0) {
				zumx1+=vec[j].first;
				zumy1+=vec[j].second;
				used2[j] = true;
			}
		}
		rep(j,n) {
			if(!used2[j]) {
				zumx2+=vec[j].first;
				zumy2+=vec[j].second;
			}
		}

		int sumx3 = 0;
		int sumy3 = 0;
		rep(j,n) {
			if(d[i][j]>=0) {
				sumx3+=vec[j].first;
				sumy3+=vec[j].second;
			}
		}
		int sumx4 = 0;
		int sumy4 = 0;
		rep(j,n) {
			if(d[i][j]<=0) {
				sumx4+=vec[j].first;
				sumy4+=vec[j].second;
			}
		}
		long double dist1 = std::sqrtl((long double)(sumx1*sumx1) + (long double)(sumy1*sumy1));
		long double dist2 = std::sqrtl((long double)(sumx2*sumx2) + (long double)(sumy2*sumy2));
		long double zdist1 = std::sqrtl((long double)(zumx1*zumx1) + (long double)(zumy1*zumy1));
		long double zdist2 = std::sqrtl((long double)(zumx2*zumx2) + (long double)(zumy2*zumy2));
		long double dist3 = std::sqrtl((long double)(sumx3*sumx3) + (long double)(sumy3*sumy3));
		long double dist4 = std::sqrtl((long double)(sumx4*sumx4) + (long double)(sumy4*sumy4));
		max = std::max({max,dist1,dist2,dist3,dist4,zdist1,zdist2});
	}
	print(max);

	return 0;
}

#include "bits/stdc++.h"
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define RREP(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define FOR(i, s, n) for (int i = s; i < (int)n; ++i)
#define RFOR(i, s, n) for (int i = (int)n - 1; i >= s; --i)
#define ALL(a) a.begin(), a.end()
#define IN(a, x, b) (a <= x && x < b)
template<class T>inline void out(T t){cout << t << "\n";}
template<class T,class... Ts>inline void out(T t,Ts... ts){cout << t << " ";out(ts...);}
template<class T>inline bool CHMIN(T&a,T b){if(a > b){a = b;return true;}return false;}
template<class T>inline bool CHMAX(T&a,T b){if(a < b){a = b;return true;}return false;}
constexpr int INF = 1e18;

int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
int lcm(int x, int y)
{
	return (x * y / gcd(x, y));
}

signed main(){
	int N,M;
	cin >> N >> M;
	vector<int>a(N);
	REP(i,N){
		cin >> a[i];
		a[i] >>= 1;
	}
	int beki = -1;
	REP(i,N){
		int cnt = 0;
		while(a[i] % 2 == 0){
			++cnt;
			a[i] >>= 1;
		}
		if(beki == -1)beki = cnt;
		else{
			if(beki != cnt){
				out(0);
				return 0;
			}
		}
	}
	REP(i,beki)M >>= 1;
	int l = 1;
	REP(i,N){
		l = lcm(l,a[i]);
		if(l > M){
			cout << 0 << endl;
			return 0;
		}
	}
	out((M / l + 1) / 2);
}
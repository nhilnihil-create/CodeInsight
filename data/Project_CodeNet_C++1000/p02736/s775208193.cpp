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


signed main(){
	int N;
	cin >> N;
	string s;
	cin >> s;
	vector<int>a(N);
	REP(i,N){
		a[i] = s[i] - '0';
	}
	vector<int>b(N - 1);
	int flg = 0;
	REP(i,N - 1){
		b[i] = abs(a[i] - a[i + 1]);
		if(b[i] == 1)flg = 1;
	}
	REP(i,N)if(flg && b[i] == 2)b[i] = 0;
	int sum = 0;
	REP(i,N - 1){
		if(b[i] == 0)continue;
		sum += (N - 2) == ((N - 2) | (N - 2 - i));
		sum %= 2;
	}
	if(flg == 0 && sum)out(2);
	else if(flg && sum)out(1);
	else out(0);
}
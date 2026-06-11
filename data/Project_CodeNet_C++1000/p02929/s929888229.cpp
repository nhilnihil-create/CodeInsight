#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
const long long MOD = 1e9 + 7, INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}



signed main(){
	int N;
	cin>>N;
	string s;
	cin>>s;
	int cnt = 0, ans = 1;
	REP(i,2*N){
		if(s[i]=='B'&&cnt % 2 == 0){
			cnt++;
		}else if(s[i]=='W'&&cnt % 2){
			cnt++;
		}else{
			ans *= cnt;
			cnt--;
		}
		ans %= MOD;
	}
	if(cnt != 0){
		cout << 0 << endl;
		return 0;
	}
	REP(i,N){
		ans *= i + 1;
		ans %= MOD;
	}
	cout << ans << endl;
}

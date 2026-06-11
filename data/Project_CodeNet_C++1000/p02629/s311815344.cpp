#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	ll N;
	cin >> N;
	N -= 1;
	string ans = "";
	ll M = 26;
	while(1) {
		int t = N % 26;
		ans = (char)('a' + t) + ans;
		/*if(N % 26 == 0) {
			N /=26;
			N -= 1;
		}
		else N /= 26;
		*/
		N -= M;
		if(N < 0) break;
		N /= 26;
		//if(N >= 26) N -= 1;
	}
	cout << ans << endl;

  return 0;
}

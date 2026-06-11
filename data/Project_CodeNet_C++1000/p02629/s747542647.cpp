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
	string ans = "";
	ll M = 1;
	while(1) {
		int t = N % 26;
		if(t == 0) t = 26;
		ans = (char)('a' + (t-1)) + ans;
		if(N <= 26) break;
		if(N % 26 == 0) {
			N /=26;
			N -= 1;
		}
		else N /= 26;
		//if(N >= 26) N -= 1;
	}
	cout << ans << endl;

  return 0;
}

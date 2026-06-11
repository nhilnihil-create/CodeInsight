#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//#include "atcoder/all"
//using namespace atcoder;

int digits(ll n){
	if(n == 0) return 1;
	int res = 0;
	while(n > 0){
		n /= 10;
		res++;
	}
	return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> s(m);
	vector<char> c(m);
	rep(i,m) cin >> s[i] >> c[i];
	rep(i,1000){
		if(digits(i) != n) continue;
		bool ok = true;
		string t = to_string(i);
		rep(j,m){
			if(t[s[j]-1] != c[j]){
				ok = false;
				break;
			}
		}
		if(ok){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}

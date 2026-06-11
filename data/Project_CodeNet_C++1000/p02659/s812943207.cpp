#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//#include "atcoder/all"
//using namespace atcoder;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll a;
	string b;
	cin >> a >> b;
	int B = 0;
	rep(i,b.size()){
		if(b[i] == '.') continue;
		B = B * 10 + (b[i] - '0');
	}
	ll ans = a * B / 100;
	cout << ans << endl;
	return 0;
}
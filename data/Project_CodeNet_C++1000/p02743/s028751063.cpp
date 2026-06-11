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
	ll a, b, c;
	cin >> a >> b >> c;
	if(c == 0 || c-a-b < 0 || a*b*4 >= (c-a-b)*(c-a-b)) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
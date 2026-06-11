#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	rep(i,h){
		rep(j,w){
			if((b <= i && j < a) || (i < b && j >= a)) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
	return 0;
}

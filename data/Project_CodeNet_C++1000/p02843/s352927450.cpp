#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool buy[100110];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int x;
	cin >> x;
	buy[0] = true;
	rep(i,x){
		rep(j,6){
			buy[i+100+j] |= buy[i];
		}
	}
	cout << (buy[x] ? '1' : '0') << endl;
	return 0;
}
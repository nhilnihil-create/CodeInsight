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
	int mx1 = 0, mx2 = 0;
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n){
		cin >> a[i];
		if(mx1 < a[i]){
			mx2 = mx1;
			mx1 = a[i];
		}
		else if(mx2 < a[i]){
			mx2 = a[i];
		}
	}
	rep(i,n){
		if(a[i] == mx1) cout << mx2 << endl;
		else cout << mx1 << endl;
	}
	return 0;
}

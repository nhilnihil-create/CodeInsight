#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int a[3][3];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	rep(i,3)rep(j,3) cin >> a[i][j];
	int n;
	cin >> n;
	rep(i,n){
		int b;
		cin >> b;
		rep(j,3)rep(k,3){
			if(a[j][k] == b) a[j][k] = -1;
		}
	}
	bool yes = false;
	rep(i,3){
		bool ok = true;
		rep(j,3){
			if(a[i][j] != -1) ok = false;
		}
		if(ok) yes = true;
	}
	rep(j,3){
		bool ok = true;
		rep(i,3){
			if(a[i][j] != -1) ok = false;
		}
		if(ok) yes = true;
	}
	if(a[0][0] == -1 && a[1][1] == -1 && a[2][2] == -1) yes = true;
	if(a[0][2] == -1 && a[1][1] == -1 && a[2][0] == -1) yes = true;
	cout << (yes ? "Yes" : "No") << endl;
	return 0;
}

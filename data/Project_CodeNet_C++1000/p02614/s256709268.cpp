#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int h,w,k;
	cin >> h >> w >> k;
	vector<string> c(h);
	int ans = 0;
	rep(i,h) cin >> c[i];
	rep(is,1<<h)rep(js,1<<w){
			int counts = 0;
		rep(i,h)rep(j,w){
			if(is>>i&1) continue;
			if(js>>j&1) continue;
			if(c[i][j] == '#') counts++;
		}
		if(counts == k) ans++;
	}
	cout << ans << endl;
	}
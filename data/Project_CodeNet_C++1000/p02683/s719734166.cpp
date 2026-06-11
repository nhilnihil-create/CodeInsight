#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

#define INF 1e9

int n, m, x;
int main() {
	cin >> n >> m >> x;
	vector<int> c(n);
	vector<vector<int>> a(n, vector<int>(m));
	rep(i, 0 ,n){
		cin >> c[i];
		rep(j, 0 ,m) cin >> a[i][j];
	}
	
	
	int ans =INF;
	rep(bit, 0, 1<<n){
		vector<int> skill(m);
		int nc = 0;
		rep(i, 0, n){	
			if(bit>>i & 1){
				rep(k, 0, m) skill[k] += a [i][k];
				nc += c[i];
			}
		}
		bool overedX = true;
		rep(i, 0, m) if(skill[i] < x) overedX = false;
		if(overedX) ans = min(ans, nc);
	}
	
	
	if(ans == INF) ans = -1;
	cout << ans << endl;

    return 0;
}

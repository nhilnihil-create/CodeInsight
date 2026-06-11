#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int m[102][102]; 
int r[102][102];
int main() {
	int h,w;
	cin >> h >> w;
	rep(i,h) rep(j,w) {
		char c; cin >> c;
		m[i][j] = (c == '#');
	}
	
	rep(i,h) {
		rep(j,w) {
			if (i==0 && j == 0) r[i][j] = m[i][j];
			else {
				int p = i ? r[i-1][j]+(m[i][j]>m[i-1][j]) : 200;
				int q = j ? r[i][j-1]+(m[i][j]>m[i][j-1]) : 200;
				r[i][j] = min(p,q); 
			}
		} 
	}
	cout << r[h-1][w-1] << endl;
  return 0;
}
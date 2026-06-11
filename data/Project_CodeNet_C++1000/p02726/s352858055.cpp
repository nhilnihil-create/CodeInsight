#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=2e3;
int n, x, y, ans[mxN];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> x >> y, --x, --y;
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			int d=min(j-i, abs(i-x)+1+abs(j-y));
			++ans[d];
		}
	}
	for(int i=1; i<n; ++i)
		cout << ans[i] << "\n";
}
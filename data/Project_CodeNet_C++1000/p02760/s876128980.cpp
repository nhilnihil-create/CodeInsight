#include<bits/stdc++.h>			
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;
 
 bool appear[101], mark[100][100];
void solve() {
	int grid[3][3];
	bool flag = false;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			cin >> grid[i][j];
			appear[grid[i][j]] = 1;
			}
		}
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			if(appear[x]) {
				for(int j = 0; j < 3; ++j) {
					for(int k = 0; k < 3; ++k) {
						if(grid[j][k] == x) mark[j][k] = 1;
						}
					}
				}
			}
			for(int i = 0; i < 3; ++i) {
				if(mark[0][i] && mark[1][i] && mark[2][i]) flag = true;
				}
				
			for(int i = 0; i < 3; ++i) {
				if(mark[i][0] && mark[i][1] && mark[i][2]) flag = true;
				}
				if(mark[0][0] && mark[1][1] && mark[2][2]) flag = true;
				if(mark[1][1] && mark[0][2] && mark[2][0]) flag = true;
				if(flag) cout << "Yes" << endl;
				else cout << "No" << endl;
		
}

 
	
 
int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	int t;
	solve();
	return 0;
}
 
 
 

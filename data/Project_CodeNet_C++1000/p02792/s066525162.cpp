#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,i;
	cin >> n;
	vector<vector<int>> v(10, vector<int>(10));
	for (int i = 1; i <= n; ++i) {
		int a = i % 10;
		int b = i;
		while (b >= 10) b /= 10;
		v[a][b]++;
	}
	int ans = 0;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			ans+=v[i][j]*v[j][i];
		}
	}
	cout << ans << endl;
 	return 0;
}
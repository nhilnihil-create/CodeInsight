#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, m;
	cin >> n >> m;
	int k = pow(2, n);
	vector<int> dp(k, 1000000000);
//	vector<P> key(m);
	vector<vector<int>> key(m, vector<int>(2));
	rep(i, m){
		int a, b, b0;
		cin >> a >> b;
		int c = 0;
		rep(j, b){
			cin >> b0;
			b0--;
			c += pow(2, b0);
		}
		key[i][0] = a;
		key[i][1] = c;
	}
	dp[0] = 0;
	rep(i, k){
		rep(j, m){
			int l = i;
			l |= key[j][1];
			dp[l] = min(dp[l], dp[i] + key[j][0]);
		}
	}
	if(dp[k-1] != 1000000000){
		cout << dp[k-1] << endl;
	}else{
		cout << -1 << endl;
	}
	return 0;
}
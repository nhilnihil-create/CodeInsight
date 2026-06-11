#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int h, n;
  	cin >> h >> n;
  	vector<int> a(n), b(n);
  	rep(i, n) cin >> a[i] >> b[i];
  	vector<int> dp(h+1, 1e9);
  	dp[0] = 0;
  	
	rep(i, n){
    	rep(j, h){
          	int nj = min(j+a[i], h);
        	dp[nj] = min(dp[nj], dp[j]+b[i]);
        }
    }
	
  	cout << dp[h] << endl;
}
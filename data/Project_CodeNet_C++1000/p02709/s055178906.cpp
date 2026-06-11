#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

ll dp[2005][2005];

int main(){
	int n;
  	cin >> n;
  	vector<int> a(n);
  	rep(i, n) cin >> a[i];
  	
  	vector<P> p;
  	rep(i, n) p.emplace_back(a[i], i);
  	sort(p.rbegin(), p.rend());
  	
  	rep(i, n){
    	int pi = p[i].second;
      	rep(l, i+1){
        	int r = i-l;
          	dp[i+1][l+1] = max(dp[i+1][l+1], dp[i][l]+ll(pi-l)*a[pi]);
            dp[i+1][l] = max(dp[i+1][l], dp[i][l]+ll((n-r-1)-pi)*a[pi]);
        }
    }
  
  	ll ans = 0;
  	rep(i, n+1) ans = max(ans, dp[n][i]);
  	cout << ans << endl;
}
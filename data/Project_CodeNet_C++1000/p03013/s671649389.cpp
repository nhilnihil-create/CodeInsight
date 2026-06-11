#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1000000007;

ll F(int x){
	ll dp[100000] = {0};
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= x; i++){
		dp[i] = dp[i-1] + dp[i-2];
    dp[i]%=INF;
	}
	return dp[x];
}

int main() {
 int n,m; cin >> n >> m;
 if(m==0){
   cout << F(n) << endl;
   return 0;
 }
 vector<int> s(m);
  cin >>s[0];
 for(int i=1;i<m;i++){
   cin >> s[i];
    if(s[i]-s[i-1]==1){
      cout << 0 << endl;
      return 0;
    }
 }

 ll ans=F(s[0]-1);ans%=INF;
 for(int i=1;i<m;i++){
   ans*=F(s[i]-s[i-1]-2);
   ans%=INF;

 }
 ans*=F(n-s[m-1]-1);
 ans%=INF;
 cout << ans << endl;
}

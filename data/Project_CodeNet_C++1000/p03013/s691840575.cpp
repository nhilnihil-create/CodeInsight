#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll dp[100005];
 
int main(){
int n, m;
cin >>n >>m;
vector<bool> ok(n+1, true);
for(int i = 0; i<m; i++){
 int a; cin >> a;
 ok[a] = false;
}
 
dp[0]= 1;
for(int now = 0; now<n; now++){
  for(int next = now+1; next<=min(n, now+2);next++){
     if(ok[next]){
           dp[next] += dp[now];
            dp[next] %= 1000000007;
          }
      }
  }
cout << dp[n] << endl;
return 0;
}

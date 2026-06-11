#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main(){
    int n,m; cin >> n >> m;
    vector<bool> hole(n+1,true);
    for(int i=0;i<m;i++){
      int a; cin >> a;
      hole.at(a) = false;
    }

    vector<ll> dp(n+1,0);
    dp.at(0) = 1;

    for(int i=1;i<=n;i++){
      if(i==1){
        if(hole.at(i)) dp.at(i)=1;
      }else{
        if(hole.at(i)){
          dp[i]=(dp[i-1]+dp[i-2])%MOD;
        }else{
          dp[i]=0;
        }
      }
    }

    cout << dp.at(n) << endl;

    return 0;

}

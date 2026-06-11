//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;

typedef long long ll;

#define MOD 1000000007

class Comb{
private:
  ll *fac,*finv,*inv;
public:
  Comb(){
    fac = new ll[1000000];
    finv = new ll[1000000];
    inv = new ll[1000000];
    fac[0] = 1;
    for(int i=1;i<1000000;i++){
      fac[i] = i*fac[i-1];
      fac[i] %= MOD;
    }
    inv[1] = 1;
    for(int i=2;i<1000000;i++){
      inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
    }
    finv[0] = 1;
    for(int i=1;i<1000000;i++){
      finv[i] = inv[i]*finv[i-1];
      finv[i] %= MOD;
    }
  }
  ll calc(ll n,ll k){
    ll c = fac[n];
    c *= finv[k];c %= MOD;
    c *= finv[n-k];c %= MOD;
    return c;
  }
};

int debug(vector<int>& nums, int target) {
        if(target == 0) return 0;
        int dp[target+1];
        for(int i=0;i<target+1;i++){
            dp[i] = 0;
        }
        
        dp[0] = 1;
        for(int i=1;i<target+1;i++){
            for(int j=0;j<nums.size();j++){
                if(i - nums[j] >= 0){
                    //cout << i - nums[j] << endl;
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }

int main(){
  int m,d;
  cin >> m >> d;
  int ans = 0;
  for(int i=1;i<m+1;i++){
    for(int j=1;j<d+1;j++){
      if((j/10) < 2 || (j%10) < 2) continue;
      if(i == (j/10)*(j%10)) ans += 1;
    }
  }
  cout << ans << endl;
  return 0;
}

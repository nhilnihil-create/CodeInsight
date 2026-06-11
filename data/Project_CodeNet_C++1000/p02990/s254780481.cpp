//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const ll mod=1e9+7;

ll c[2001][2001] = {0};
int main(){
  ll n,k;
  cin >> n >> k;
  rep(i,2001){
    c[i][0] = 1;
    c[i][i] = 1;
  }

  rep(i,2001){
    for(int j = 1; j < i; j++){
      c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
    }
  }

  ll ans;
  for(int i = 1; i <= k; i++){
    ans = (c[n-k+1][i]*c[k-1][i-1])%mod;
    printf("%lld\n", ans);
  }

  return 0;
}

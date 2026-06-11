#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout <<(#x)<<" is "<<(x)<<endl
#define debug cout <<"hi"<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD=1e9+7;
const int INF32=1<<30;
const ll INF64=1LL<<60;

void solve(){
  int n,m; cin >>n >>m;
  int b[n+1]; memset(b,1,sizeof(b));
  for(int i=0; i<m; i++){
    int x; cin >>x;
    b[x]=0;
  }
  int dp[n+1]; memset(dp,0,sizeof(dp)); dp[0]=1;
  for(int i=0; i<n; i++) for(int j=i+1; j<=min(n,i+2); j++) if(b[j]){
    dp[j]+=dp[i]; dp[j]%=MOD;
  }
  cout <<dp[n];
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  solve();
return 0;}
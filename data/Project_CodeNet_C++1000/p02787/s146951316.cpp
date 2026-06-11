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
  int h,n; cin >>h >>n;
  vector<int>a(n),b(n),dp(h+1,INT_MAX); dp[0]=0;
  for(int i=0; i<n; i++) cin >>a[i] >>b[i];
  for(int i=1; i<=h; i++) for(int j=0; j<n; j++)
  dp[i]=min(dp[i],dp[max(i-a[j],0)]+b[j]);
  cout <<dp[h];
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  solve();
return 0;}
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
  int n,l; cin >>n >>l;
  if(l<=0&&n+l>0) cout <<n*(2*l+n-1)/2;
  else if(l+n-1<0) cout <<(n-1)*(2*l+n-2)/2;
  else cout <<(n-1)*(2*l+n)/2;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  solve();
return 0;}
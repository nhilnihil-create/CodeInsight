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
  int n,d; cin >>n >>d;
  int x[n][d],cnt=0;
  for(int i=0; i<n; i++) for(int j=0; j<d; j++) cin >>x[i][j];
  for(int i=0; i<n-1; i++) for(int j=i+1; j<n; j++){
    int dis=0;
    for(int k=0; k<d; k++) dis+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
    for(int k=1; k<127; k++) if(k*k==dis){cnt++; break;}
  }
  cout <<cnt;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  solve();
return 0;}
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
  int n,k; cin >>n >>k;
  string s; cin >>s;
  int cnt=0;
  for(int i=0; i<n-1; i++){
    if(s[i]!=s[i+1]) cnt++;
  }
  if(cnt%2){    
    if(k<=cnt/2) cout <<n-1-cnt+2*k;
    else cout <<n-1;
  }
  else{
    k=min(cnt/2,k);
    cout <<n-1-cnt+2*k;
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  solve();
return 0;}
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
  int a[n],ans,l=1,r=1;
  for(auto &i:a){
    cin >>i;
    r=max(r,i);
  }
  while(l<=r){
    int m=(l+r)/2,cnt=0;
    for(auto i:a) cnt+=(i-1)/m;
    if(cnt>k) l=m+1;
    else{ans=m; r=m-1;}
  }
  cout <<ans;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  solve();
return 0;}
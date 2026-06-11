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
  int n,k,r,s,p; cin >>n >>k >>r >>s >>p;
  int ans=0; string te="";
  map<char,char>win;
  win['r']='p'; win['s']='r'; win['p']='s';
  string t; cin >>t;
  for(int i=0; i<n; i++){
    te+=win[t[i]];
    if(i>=k&&te[i]==te[i-k]) te[i]='x';
    if(te[i]=='r') ans+=r;
    else if(te[i]=='s') ans+=s;
    else if(te[i]=='p') ans+=p;
  }
  cout <<ans;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  solve();
return 0;}
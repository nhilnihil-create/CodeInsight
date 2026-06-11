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
  int R=0,S=0,P=0,cnt=1; vector<vector<char>>v(k);
  for(int i=0; i<n; i++){
    char c; cin >>c;
    v[i%k].push_back(c);
  }
  for(int i=0; i<k; i++){
  if(v[i].size()==1){
    if(v[i][0]=='s') R++;
    else if(v[i][0]=='p') S++;
    else P++;
    cnt=1;
  }
  else for(int j=0; j<v[i].size()-1; j++){
    if(v[i][j]==v[i][j+1]) cnt++;
    else{
      if(v[i][j]=='s') R+=(cnt+1)/2;
      else if(v[i][j]=='p') S+=(cnt+1)/2;
      else P+=(cnt+1)/2;
      cnt=1;
    }
    if(j==v[i].size()-2&&v[i][j]==v[i][j+1]){
      if(v[i][j+1]=='s') R+=(cnt+1)/2;
      else if(v[i][j+1]=='p') S+=(cnt+1)/2;
      else P+=(cnt+1)/2;
      cnt=1;
    }
    else if(j==v[i].size()-2){
      if(v[i][j+1]=='s') R++;
      else if(v[i][j+1]=='p') S++;
      else P++;
      cnt=1;
    }
  }
  }
  cout <<R*r+S*s+P*p;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  solve();
return 0;}
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const int INF=1e9;

int main(){
  int a,b,m;
  int mina=INF,minb=INF;
  cin >>a>>b>>m;
  vector<int> va(a),vb(b);
  vector<vector<int>> vm(m,vector<int>(3));
  rep(i,a) {
    cin >>va[i];
    mina=min(mina,va[i]);
  }
  rep(i,b){
    cin >>vb[i];
    minb=min(minb,vb[i]);
  }
  int ans=mina+minb;
  rep(i,m){
    int x,y,c;
    cin >>x>>y>>c;
    --x; --y;
    ans=min(ans,va[x]+vb[y]-c);
  }
  cout<<ans<<endl;
  
  return 0;
  
  
}
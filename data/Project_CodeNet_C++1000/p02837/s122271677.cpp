#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  int n;
  cin>>n;
  vector<vector<int>>l(n);
  rep(i,n){
    int a;
    cin>>a;
    rep(j,a){
      int x,y;
      cin>>x>>y;
      l[i].push_back(x);
      l[i].push_back(y);
    }
  }
  int ans=0;
  for(int tmp=0;tmp<(1<<15);tmp++){
    bitset<15>t(tmp);
    int tans=0;
    bool check=true;
    for(int i=0;i<n;i++){
      if(t.test(i)){
        tans++;
        for(int j=0;j<l[i].size();j+=2){
          if(l[i][j+1]==1 && (!t.test(l[i][j]-1))) check=false;
          if(l[i][j+1]==0 && (t.test(l[i][j]-1))) check=false;
        }
      }
    }
    if(check) ans=max(ans,tans);
  }
  cout<<ans<<endl;
}
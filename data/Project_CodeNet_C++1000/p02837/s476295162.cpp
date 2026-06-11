#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin>>n;
  
  vector<pair<int,int>> p[16];
  int a,x,y;
  rep(i,n){
    cin>>a;
    rep(j,a){
      cin>>x>>y;
      p[i].push_back({x,y});
    }
  }
  
  int ma=0;
  for(int i=0;i<(1<<n);i++){
    bool b = true;
    int cnt=0;
    for(int j=0;j<n;j++){
      if((i>>j)&1){
        cnt++;
        for(auto u:p[j]){
          if(u.second==1 && ((1<<(u.first-1))&i)==0) b=false;
          if(u.second==0 && ((1<<(u.first-1))&i)>0) b=false;
        }
      }
    }
    if(b){
      if(cnt>ma) ma=cnt;
    }
  }
  
  cout<<ma<<endl;
    
  return 0;
}
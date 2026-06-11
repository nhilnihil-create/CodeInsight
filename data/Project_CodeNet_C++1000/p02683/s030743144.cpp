#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n,m,x;
  cin>>n>>m>>x;
  vector<int> c(n);
  vector<vector<int>> avi(n,vector<int>(m));
  rep(i,n){
    cin>>c[i];
    rep(j,m){
      cin>>avi[i][j];
    }
  }
  int min_cost = 1200010;
  bool ch = false;
  for(int tmp=0; tmp<(1<<n); tmp++){ 
    bitset<12> b(tmp);
    int tmp_cost = 0;
    vector<int> tmp_avi(m,0);
    rep(i,n){ 
      if(b.test(i)){
        tmp_cost+=c[i];
        rep(j,m){
          tmp_avi[j]+=avi[i][j];
        }
      }
    } 
    bool suc =true;
    rep(i,m){
      if(tmp_avi[i]<x){
        suc = false;
      }
    }
    if(suc){
      min_cost=min(min_cost,tmp_cost);
      ch = true;
    }
  }
  if(ch){
    cout<<min_cost<<endl;
  }else{
    cout<<-1<<endl;
  }
}


#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
vector<vector<int>> vec;
int n,m,q;
void num(vector<int> v){
    if(v.size()==10){
        vec.push_back(v);
    }
    else if(v.size()==0){
        rep(i,m){
            v.push_back(i+1);
            num(v);
            v.pop_back();
        }
    }
    else{
        int x=v.size();
        int y=v[x-1];
        for(int i=y;i<=m;i++){
            v.push_back(i);
            num(v);
            v.pop_back();
        }
    }
}

int main() {

  cin >> n >> m >> q;
  vector<int> emp;
  num(emp);
  vector<vector<int>> qs(q,vector<int>(4));
  rep(i,q) cin >> qs[i][0] >> qs[i][1] >> qs[i][2] >> qs[i][3];
  int ans=0;
  for(vector<int> vv:vec){
      int count=0;
      rep(i,q){
          int a=qs[i][0];
          int b=qs[i][1];
          int c=qs[i][2];
          int d=qs[i][3];
          a--;b--;
          if(vv[b]-vv[a]==c) count+=d;
      }
      ans=max(ans,count);
  }
  cout << ans << endl;
}
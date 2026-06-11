#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N,M,X; cin >>N >>M >>X;
  vector<int> C(N);
  vector<vector<int>> A(N,vector<int>(M));
  rep(i,0,N) {
    cin >>C[i];
    rep(j,0,M) {
      cin >>A[i][j];
    }
  }

  int ans=INT_MAX;
  int all=1<<N;
  rep(mask,0,all) {
    vector<int> level(M);
    int cost=0;
    rep(i,0,N) {
      if (mask>>i&1) {
        cost+=C[i];
        rep(j,0,M) {
          level[j]+=A[i][j];
        }
      }
    }
    bool flag=true;
    rep(j,0,M) {
      if (level[j]<X) {
        flag=false;
      }
    }
    if (flag) {
      ans=min(ans,cost);
    }
  }
  if (ans==INT_MAX) {
    cout <<-1 <<endl;
  } else {
    cout <<ans <<endl;
  }
  return 0;
}

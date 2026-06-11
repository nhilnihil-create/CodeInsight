#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int A,B,M;
  cin >>A >>B >>M;
  vector<int> a(A), b(B);
  rep(i,A) cin >>a[i];
  rep(i,B) cin >>b[i];
  vector<vector<int>> c(M, vector<int>(3));
  rep(i,M){
    rep(j,3){
      cin >>c[i][j];
    }
  }
  int amin=1e8, bmin=1e8;
  rep(i,A){
    amin = min(amin, a[i]);
  }
  rep(i,B){
    bmin = min(bmin, b[i]);
  }
  int curMin = amin + bmin;
  rep(i,M){
    curMin = min(curMin, a[c[i][0]-1]+b[c[i][1]-1]-c[i][2]);
  }
  cout << curMin << endl;
  return 0;
}
#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  vector<vector<int>> A(3,vector<int>(3));
  vector<vector<bool>> B(3,vector<bool>(3,0));
  rep(i,3)rep(j,3) cin >> A[i][j];
  int N,cnt=0;
  cin >> N;
  vector<int> b(N);
  rep(i,N) cin>> b[i];
  string ans="No";
  rep(k,N){rep(i,3)rep(j,3){
   if(A[i][j]==b[k]){
     B[i][j]=1;
     cnt++;
   }
  }
  }
  if(cnt>6) ans = "Yes";
  else if(cnt>2){
    vector<bool> temp(8,1);
    rep(i,3)rep(j,3) temp[i] = (temp[i] && B[i][j]);
    rep(j,3)rep(i,3) temp[3+j] = (temp[3+j] && B[i][j]);
    rep(i,3) temp[6] = (temp[6] && B[i][i]);
    rep(i,3) temp[7] = (temp[7] && B[2-i][i]);
    rep(i,8) if(temp[i]==1)ans="Yes";
  }
  
  cout << ans << endl;
  
  return 0;
}

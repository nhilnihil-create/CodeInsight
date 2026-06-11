#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;
void YN(bool x){
  if(x) cout<<"Yes";
  else cout<<"No";
}
int main() {
  vector<vector<int>> A(3,vector<int>(3));
  vector<vector<bool>> S(3,vector<bool>(3,false));
  rep(i,3){
    rep(j,3){
      cin>>A[i][j];
    }
  }
  int N; cin>>N;
  rep(q,N){
    int B; cin>>B;
    rep(i,3){
      rep(j,3){
        if(B==A[i][j]) S[i][j]=true;
      }
    }
  }
  bool bingo=false;
  if(S[0][0]&&S[1][1]&&S[2][2]) bingo=true;
  if(S[0][2]&&S[1][1]&&S[2][0]) bingo=true;
  rep(i,3) if(S[i][0]&&S[i][1]&&S[i][2]) bingo=true;
  rep(i,3) if(S[0][i]&&S[1][i]&&S[2][i]) bingo=true;
  YN(bingo);
}

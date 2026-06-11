#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //範囲外参照とループの初期化に注意！

const int INF = 100100100;
int main() {
  int N,M,X;
  cin >> N >> M >> X;
  vector<int> cost(N);
  vector<vector<int>> A(N,vector<int>(M));
  rep(i,N){
    cin >> cost[i];
    rep(j,M){
      cin >> A[i][j];
    }
  }
  int ans = INF;
  rep(is,1<<N){
    bool can = true;
    int sum = 0;
    vector<int> und(M,0);
    rep(i,N){
      if(is>>i&1){
        sum += cost[i];
        rep(j,M){
          und[j] += A[i][j];
        }
      }
    }
    rep(i,M){
      if(und[i] < X) can = false;
    }
    if(can){
      ans = min(ans,sum);
    }
  }
  if(ans == INF) ans = -1;
  cout << ans << endl;
}
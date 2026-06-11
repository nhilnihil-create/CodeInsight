#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,M;cin >> N >> M;
  vector<int> A(M);
  vector<int> C(M,0);
  int INF = 0;
  for(int i=0;i<M;i++){
    int B;
    cin >> A[i] >> B;
    INF += A[i];
    for(int b=0;b<B;b++){
      int c;cin >> c;
      C[i] |= (1<<(c-1));
    }
    //cout << i << " " << A[i] << " " << C[i] << endl;
  }
  INF ++;
  vector<vector<int>> DP(M+1,vector<int>((1<<N),INF));
  DP[0][0]=0;
  for(int i=0;i<M;i++){
    for(int bit=0;bit<(1<<N);bit++){
      DP[i+1][bit] = DP[i][bit];
    }
    for(int bit=0;bit<(1<<N);bit++){
      DP[i+1][bit|C[i]] = min(DP[i+1][bit|C[i]],DP[i][bit]+A[i]);
    }
  }
  //for(int i=0;i<=M;i++){
  //  for(int bit=0;bit<(1<<N);bit++){
  //    if(DP[i][bit]==INF){
  //      cout << "INF";
  //    }else{
  //      cout << DP[i][bit];
  //    }
  //    cout << " ";
  //  }
  //  cout << endl;
  //}
  int ans = DP[M][(1<<N)-1];
  if(ans>=INF){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
}
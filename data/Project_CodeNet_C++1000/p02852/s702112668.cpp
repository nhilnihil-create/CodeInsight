#include <bits/stdc++.h>
using namespace std;
int INF = 10000000;
int main(){
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  //dp
  bool flg = true;
  vector<int> dp(N + 1, INF);
  dp[0] = 0;
  for (int i = 1; i <= N; i++){
    if (S[i] == '0'){
      int j = max(0, i - M);
      while (S[j] == '1'){
        j++;
      }
      if (j >= i){
        flg = false;
        break;
      } else {
        dp[i] = dp[j] + 1;
      }
    }
  }
  if (!flg){
    cout << -1;
  } else {
    int A = dp[N];
    //逆DP
    vector<int> dp2(N + 1, INF);
    dp2[N] = 0;
    for (int i = N - 1; i >= 0; i--){
      if (S[i] == '0'){
        int j = min(N, i + M);
        while (S[j] == '1'){
          j--;
        }
        dp2[i] = dp2[j] + 1;
      }
    }
    vector<int> R;
    int j = 0;
    for (int i = A - 1; i >= 0; i--){
      while (dp2[j] != i){
        j++;
      }
      R.push_back(j);
    }
    cout << R[0];
    for (int i = 1; i < A; i++){
      cout << ' ' << R[i] - R[i - 1];
    }
    /*
    cout << endl;
    for (int i = 0; i <= N; i++){
      cout << dp[i];
    }
    cout << endl;
    for (int i = 0; i <= N; i++){
      cout << dp2[i];
    }
    cout << endl;
    for (int i = 0; i < A; i++){
      cout << R[i];
    }
    cout << endl;
    */
  }
}
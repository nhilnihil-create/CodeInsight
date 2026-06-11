#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  int N;
  ll K;
  cin >> N >> K;
  int log_K = floor(log2(K));
  // cerr << N << " " << log_K << endl;
  vector<vector<int>> next(log_K + 1, vector<int>(N));

  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    // cerr << i << " : " << tmp << endl;
    next.at(0).at(i) = tmp-1;
  }

  for(int k = 0; k < log_K; k++){
    for(int i = 0; i < N; i++){
      if(next[k][i] == -1){
        next[k+1][i] = -1;
      } else { 
        next[k+1][i] = next[k][next[k][i]];
        // cerr << k+1 << " " << i << " " << next[k+1][i] << endl;
      }
    }
  }

  int ans = 0;
  for(ll k = log_K; k >= 0; k--){
    if((K>>k)&1){
      ans = next[k][ans];
    }
  }
  cout << ans+1<< endl;

}

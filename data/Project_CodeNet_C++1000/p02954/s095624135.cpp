#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  string S;
  cin >> S;
  int N = S.size();
  int log_N = floor(log2(N));
  ll K = 10000000000;
  ll log_K = floor(log2(K));
  // cerr << N << " " << log_K << endl;
  vector<vector<int>> parent(log_K + 1, vector<int>(N));
 
  for(int i = 0; i < N; i++){
    if(S[i] == 'L'){
      parent.at(0).at(i) = i-1;
    } else { 
      parent.at(0).at(i) = i+1;
    }
  }
 
  for(int k = 0; k < log_K; k++){
    for(int i = 0; i < N; i++){
      if(parent[k][i] == -1){
        parent[k+1][i] = -1;
      } else { 
        parent[k+1][i] = parent[k][parent[k][i]];
        // cerr << k+1 << " " << i << " " << parent[k+1][i] << endl;
      }
    }
  }

  vector<int> v_ans(N,0);
  for(int i = 0; i < N; i++){
    // K個上
    int ans = i;
    for(ll k = log_K; k >= 0; k--){
      if((K>>k)&1){
        ans = parent[k][ans];
      }
    }
    v_ans[ans]++;
  }
  
  
  for(int i = 0; i < N; i++){
    if(i == N-1){
      cout << v_ans[i] << endl;
    } else {
      cout << v_ans[i] << " ";
    }
  }
}

#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, Q, temp;
  long long K;
  cin >> N >> K >> Q;
  vector<int> P(N,K - Q);
  for(int i = 0; i < Q; i++){
    cin >> temp;
    P[temp - 1]++;    
  }
  for(int i = 0;  i < N; i++){
    if(P[i] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0; 
}
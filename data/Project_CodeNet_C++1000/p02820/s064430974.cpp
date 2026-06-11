#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll N, K, R, S, P;
  string T;
  cin >> N >> K >> R >> S >> P >> T;

  vector<bool> A(T.size(), true);

  ll nR=0;
  ll nS=0;
  ll nP=0;

  for(ll i=0; i<N; i++){
    if (i >= K && T[i] == T[i-K] && A[i-K]){
      A[i] = false;
      continue;
    }
    if (T[i] == 'r') ++nR;
    else if (T[i] == 's')++nS;
    else if (T[i] == 'p')++nP;
  }

  ll ret = nR*P + nS*R + nP*S;
  cout << ret << endl;

  return 0;
}
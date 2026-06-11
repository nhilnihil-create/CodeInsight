#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  ll N,K; cin >> N >> K;
  if(N > K){
    rep(i,N){
      cout << K;
    }
  }
  else{
    rep(i,K){
      cout << N;
    }
  }
}

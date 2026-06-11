#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  ll N,K; cin >> N >> K;
  if(N <= K){
    cout << "0";
    return 0;
  }
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  sort(A.begin(), A.end()); //小さい順
  rep(i,K){
    A.pop_back();
  }
  ll ans = 0;
  rep(i,A.size()){
    ans += A[i];
  }
  cout << ans;
}
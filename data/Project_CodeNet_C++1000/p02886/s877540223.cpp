#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0,ans = 0;
  cin >> N;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  for(ll i = 0;i < N-1;i++){
    for(ll j = 1;j + i < N;j++){
      ans+=A[i] * A[i+j];
    }
  }
  cout << ans;
}
  
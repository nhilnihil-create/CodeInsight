#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0,K,ans = 0;
  cin >> N >> K;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  rep(i,N){
    if(A[i] >= K){
      ans++;
    }
  }
  cout << ans;
}
  
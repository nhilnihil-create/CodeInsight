#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0;
  cin >> N;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  ll ans = 0;
  ans += A[0] + A[N-2];
  rep(i,N-2){
    ans += min(A[i],A[i+1]);
  }
  cout << ans;
}
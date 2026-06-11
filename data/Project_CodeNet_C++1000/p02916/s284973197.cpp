#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0;
  cin >> N;
  vector<ll>A(N);
  vector<ll>B(N);
  vector<ll>C(N-1);
  ll ans = 0;
  rep(i,N){
    cin >> A[i];
  }
  rep(i,N){
    cin >> B[i];
    ans += B[i];
  }
  rep(i,N-1){
    cin >> C[i];
  }
  rep(i,N-1){
    if(A[i+1] - A[i] == 1){
      ans += C[A[i]-1];
    }
  }
  cout << ans;
}
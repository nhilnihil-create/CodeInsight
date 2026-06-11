#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0,ans = 0;
  cin >> N;
  ll m = N+1;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  rep(i,N){
    if(m > A[i]){
      ans++;
      m = A[i];
    }
  }
  cout << ans;
}
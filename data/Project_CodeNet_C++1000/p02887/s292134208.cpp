#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0,ans = 1;
  cin >> N;
  vector<char>A(N);
  rep(i,N){
    cin >> A[i];
  }
  rep(i,N-1){
    if(A[i] != A[i+1]){
      ans++;
    }
  }
  cout << ans;
}
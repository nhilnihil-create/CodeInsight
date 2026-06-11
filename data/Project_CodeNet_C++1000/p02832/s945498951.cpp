#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N;
  cin >> N;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  ll j = 1;
  rep(i,N){
    if(A[i] == j){
      j++;
    }
  }
  if(j == 1){
    cout << "-1";
  }
  else{
    cout << N - j + 1;
  }
}
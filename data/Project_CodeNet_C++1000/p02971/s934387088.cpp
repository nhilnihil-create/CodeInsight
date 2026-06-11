#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0;
  cin >> N;
  vector<ll>A(N);
  vector<ll>B(N);
  rep(i,N){
    cin >> A[i];
    B[i] = A[i];
  }
  sort(A.begin(), A.end()); //小さい順
  reverse(A.begin(), A.end());
  rep(i,N){
    if(B[i] == A[0]){
      cout << A[1] << endl;
    }
    else{
      cout << A[0] << endl;
    }
  }
}
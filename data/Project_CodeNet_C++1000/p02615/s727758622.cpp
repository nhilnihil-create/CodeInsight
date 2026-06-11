#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  int N;
  cin >> N;
  vector<ll> A(N);

  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());

  ll ans = A[0];
  int t = 1;
  int count = 0;
  for(int i = 1; i < A.size() - 1; i++) {
    
    if(count < 2) { ans += A[t]; count++; }
    if(count == 2) { count = 0; t++;}
  }

  cout << ans;
  return 0;
}
#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll N, ans = 0, Nstep;
  cin >> N;
  Nstep = N;
  vector<ll> A(N);
  for(ll i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  ans = A.at(0);
  for(ll i = 1; i < N - 1; i++) {
    ans += A.at((i + 1) / 2);
  }
  cout << ans << endl;
}
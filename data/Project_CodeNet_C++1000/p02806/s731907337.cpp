#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n;
  cin >> n;
  vector<pair<string,ll>> A(n);
  for (auto& _a : A) cin >> _a.first >> _a.second;
  string x;
  cin >> x;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += A[i].second;
  }
  
  for (int i = 0; i < n; ++i) {
    sum -= A[i].second;
    if (A[i].first == x) break;
  }
  cout << sum << endl;
  

}

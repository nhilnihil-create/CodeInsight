// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int n; cin >> n;
  vector<ll> A(n), M(200001, 0);
  loop(i,0,n) cin >> A[i];
  for (auto&&a: A) M[a]++;
  ll sum = 0;
  for (ll b=1; b<=200000; b++) {
    if (M[b]<=1) continue;
    sum += (M[b])*(M[b]-1) / 2;
  }
  for (auto &&a: A) {
    if (M[a]==1) {
      cout << sum << endl;
      continue;
    }
    
    ll aSum = M[a] * (M[a]-1) / 2;
    if (M[a] == 2) {
      cout << sum - aSum << endl;
      continue;
    }
    
    ll newSum = (M[a]-2)*(M[a]-1)/2;
    cout << sum - aSum + newSum << endl;
  }
  return 0;
}

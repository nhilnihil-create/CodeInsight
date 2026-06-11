#include <bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
  ll N;
  cin >> N;
  
  ll ans = 0;
  ll n = 5;
  if (N % 2) {
    cout << 0 << endl;
    return 0;

  } else {
    while (n <= N) {
      ans += N / (n*2);
      n *= 5;
    }
    cout << ans << endl;
  }
}
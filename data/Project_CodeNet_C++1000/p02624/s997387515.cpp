#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = i; j <= N; j += i) {
      if(j % i == 0) ans += j; 
    }
  }

  cout << ans;
  return 0;
}
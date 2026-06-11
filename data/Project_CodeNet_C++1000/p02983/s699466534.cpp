#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long L, R;
  cin >> L >> R;

  long long ans = 1e7;
  for(long long i = L; i <= min(R, L + 2019); i++) {
    for(long long j = i + 1; j <= min(R, L + 2019); j++) {
      ans = min(ans, (i * j) % 2019);
    }
  }

  cout << ans << endl;

  return 0;
}

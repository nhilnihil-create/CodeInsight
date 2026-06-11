#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> v(N);
  for(int i=0; i<N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  
  if (v[0] == 0) cout << 0 << endl;
  else {
    int check = 0;
    ll result = v[0];
    for(int i=1; i<N; i++) {
      if(result > 1000000000000000000/v[i]) {
        cout << -1 << endl;
        check = 1;
        break;
      }
      result *= v[i];
    }
    if (check == 0) cout << result << endl;
  }
  return 0;
}
#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll L, R, mi = 2000000000;
  cin >> L >> R;
  if((L / 2019 + 1) * 2019 <= R) cout << 0 << endl;
  else {
    for(ll i = L; i <= R - 1; i++) {
      for(ll j = i + 1; j <= R; j++) {
        if(((i % 2019) * (j % 2019) % 2019) < mi) mi = ((i % 2019) * (j % 2019) % 2019);
      }
    }
    cout << mi << endl;
  }
}
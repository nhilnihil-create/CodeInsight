#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 

int main() {
  int k;
  cin >> k;
  vector<ll> x(k+5);
  int i = 1, j = 1;
  while (j <= k) {
    if (j < 10) {
      x[j] = j;
      j++;
    }
    else {
      if (x[i]%10 == 0) {
        x[j] = x[i]*10 + 0;
        j++;
        x[j] = x[i]*10 + 1;
        j++;
        i++;
      }
      else if ((x[i]-9)%10 == 0) {
        x[j] = x[i]*10 + 8;
        j++;
        x[j] = x[i]*10 + 9;
        j++;
        i++;
      }
      else {
        x[j] = x[i]*10 + x[i]%10 - 1;
        j++;
        x[j] = x[i]*10 + x[i]%10;
        j++;
        x[j] = x[i]*10 + x[i]%10 + 1;
        j++;
        i++;
      }
    }
  }
  cout << x[k] << endl;
  return 0;
}
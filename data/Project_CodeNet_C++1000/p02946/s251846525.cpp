#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int k, x;
    cin >> k >> x;
    
    rep(i,k) {
     cout << x - k + i + 1 << ' ';
     }
    rep(i,k - 1) {
     cout << x + 1 + i << ' ';
     }

}
  
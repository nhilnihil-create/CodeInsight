#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a,b;

  cin >> a >> b;

  int ma = max(a,b);
  int mi = min(a,b);

  rep(i,ma){
    cout << mi;

  }
}
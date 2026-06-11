#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int hp, n, w;
  cin >> hp >> n;
  for(int i=0; i<n; i++) {
    cin >> w;
    hp -= w;
  }
  if (hp <= 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}
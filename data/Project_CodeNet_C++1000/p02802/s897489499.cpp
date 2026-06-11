#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> pena(n, 0);
  vector<int> ac(n, 0);
  for(int i = 0; i < m; ++i) {
    int p;
    string s;
    cin >> p >> s;
    --p;
    if(ac[p]) continue;
    if(s == "AC") {
      ac[p] = 1;
    } else {
      pena[p]++;
    }
  }
  int AC = 0, PENA = 0;
  for(int i = 0; i < n; ++i) {
    AC += ac[i];
    if(ac[i]) PENA += pena[i];
  }
  cout << AC << ' ' << PENA << endl;
}

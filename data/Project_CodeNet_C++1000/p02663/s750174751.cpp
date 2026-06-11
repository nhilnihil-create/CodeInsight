#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;

  int hdiff = h2 - h1;

  if (hdiff == 0) {
    cout << m2 - m1 - k << endl;
  }

  if (hdiff != 0) {
    cout << hdiff * 60 + (m2 - m1) - k << endl;
  }
}
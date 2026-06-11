#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, S = 0, min = 10e8;
  cin >> n;
  vector<int> v(n);
  for(int i = 0;i < n;i++) {
    cin >> v[i];
  }
  for(int i = 1;i < 101;i++) {
    S = 0;
    for(int j = 0;j < n;j++) {
      S += (v[j] - i) * (v[j] - i);
    }
    if(S < min) min = S;
  }
  cout << min << endl;
}
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, d, s = 0, x;
  cin >> n >> d;
  vector<vector<int>> v(n, vector<int>(d));
  for(int i = 0;i < n;i++) for(int j = 0;j < d;j++) cin >> v[i][j];
  for(int i = 0;i < n;i++) {
    for(int j = i + 1;j < n;j++) {
      x = 0;
      for(int k = 0;k < d;k++) x += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
      if(x == (int)(sqrt(x))*sqrt(x)) s++;
    }
  }
  cout << s << endl;
}
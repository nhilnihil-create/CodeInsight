#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int n = 100010;
  double sqn = sqrt(n);
  vector<int> v(n, 1);
  v[0] = 0;
  v[1] = 0;
  for(int i = 2;i <= sqn;i += 2) {
    if(v[i]) for(int j = 2;i * j <= n;j++) v[i * j] = 0;
    if(i == 2) i--;
  }
  int x = N;
  while(v[x] == 0) x++;
  cout << x << endl;
}
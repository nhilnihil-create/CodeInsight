#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, S = 1, m;
  cin >> N;
  vector<int> v(N);
  for(int i = 0;i < N;i++) {
    cin >> v[i];
  }
  m = v[0];
  for(int i = 1;i < N;i++) {
    if(m > v[i]) {
      S++;
      m = v[i];
    }
  }
  cout << S << endl;
}
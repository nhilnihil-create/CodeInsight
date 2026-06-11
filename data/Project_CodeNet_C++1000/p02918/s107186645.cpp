#include<bits/stdc++.h>
using namespace std;
int main () {
  int N, K;
  cin >> N >> K;
  char pr = ' ';
  int gr = 0;
  for (int i = 0; i < N; i ++) {
    char c;
    cin >> c;
    if (pr != c) gr ++;
    pr = c;
  }
  int m_gr = max(1, gr - K * 2);
  cout << N - m_gr << endl;
}
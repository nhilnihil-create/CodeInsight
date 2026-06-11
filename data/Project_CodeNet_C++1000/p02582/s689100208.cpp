#include<bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int n = 0;
  int m = 0;
  for (int i = 0; i < 3; i++) {
    if (S[i] == 'R') n++;
    else n = 0;
    m = max(n,m);
  }
  cout << m << endl;
}

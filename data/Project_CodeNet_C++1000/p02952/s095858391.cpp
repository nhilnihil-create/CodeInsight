#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int C=1, I;
  int ans=0;
  for (int i=1; i<=N; i++) {
    I=i;
    C=1;
    while (I/10>0) {
      I/=10;
      C++;
    }
    if (C%2==1) {
      ans++;
    }
  }
  cout << ans << endl;
}
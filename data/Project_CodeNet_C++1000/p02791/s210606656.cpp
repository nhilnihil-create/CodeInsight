#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int m=10000000, p, ans=0;
  for (int i=0; i<N; i++) {
    cin >> p;
    if (m>=p) {
      ans++;
      m=p;
    }
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,M,ans=0; cin >> N >> M;
  if(N>=2) ans += N*(N-1)/2;
  if(M>=2) ans += M*(M-1)/2;
  cout << ans << endl;
}
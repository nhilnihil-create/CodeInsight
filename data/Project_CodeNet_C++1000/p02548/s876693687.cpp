#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int MOD = 1000000007;

int main() {
  int N; cin >> N;
  
  int ans = 0;
  for (int a = 1; a < N; a++) {
    int cur = N / a;
    if (N % a == 0) cur--;
    ans += cur;
  }
  
  cout << ans << endl;
}   
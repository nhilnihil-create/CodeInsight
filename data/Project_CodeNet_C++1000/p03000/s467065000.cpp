#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n, x;
  cin >> n >> x;

  int a, ans = 1, sum = 0;
  REP(i,n) {
    cin >> a;
    sum += a;
    if (sum <= x) ans++;
  }
    
  cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n, l;
  cin >> n >> l;
  int sa = 0;
  if(l + n - 1 <= 0) sa = l + n - 1;
  else if(l >= 0) sa = l;
  else sa = 0;
  
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    sum += l+i-1;
  }
   
  int ans = sum - sa;
  cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n,l;
  cin >> n >> l;
  int sum = 0;
  for(int i = 1; i <= n; i++)sum += l + i -1;
  int sum2 = 0;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    sum2 = sum - l - i + 1;
    if(abs(sum2 - sum) < abs(ans - sum)) ans = sum2;
  }
  cout << ans << endl;
}
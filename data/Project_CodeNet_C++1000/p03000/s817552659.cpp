#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, x;
  cin >> n >> x;
  int a[++n];
  a[0] = 0;
  for(int i = 1; i < n; i++) cin >> a[i];
  int sum = 0, ans = 1;
  for(int i = 1; i < n; i++){
    sum = a[i] + a[i - 1];
    a[i] += a[i - 1];
    if(sum <= x) ans++;
  }
  cout << ans << endl;
  
  return 0;
}
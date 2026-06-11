#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  int a[n], b[n], m = -1;
  rep(i, n){
    cin >> a[i];
    b[i] = a[i];
    m = max(m, a[i]);
  }
  sort(a, a + n);
  rep(i, n){
    if(b[i] == m) cout << a[n - 2] << endl;
    else cout << a[n - 1] << endl;
  }

  return 0;
}
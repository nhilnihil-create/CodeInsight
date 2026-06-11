#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n,k;
  cin >> k >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int dif = 0;
  rep(i,n) {
    int sa;
    if(i == n-1) sa = a[0] - a[n-1] + k;
    else sa = a[i + 1] - a[i];
    dif = max(dif,sa);
    
  }
  cout << k - dif << endl;
}
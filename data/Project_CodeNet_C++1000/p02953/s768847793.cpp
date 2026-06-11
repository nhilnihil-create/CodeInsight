#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  int h[n];
  rep(i,n) cin >> h[i];
  int m = h[0];
  bool f = true;
  for(int i = 1; i < n; i++) {
    m = max(m,h[i]);
    if(m-h[i] > 1) f = false;
  }
  cout << (f ? "Yes" : "No") << endl;
  return 0;
}

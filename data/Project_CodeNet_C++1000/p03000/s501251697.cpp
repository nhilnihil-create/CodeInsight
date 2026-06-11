#include <bits/stdc++.h>
#define rep(s,t) for (int s = 0; s < t; s++);
using namespace std;
using ll = long long;


int main() {
  int n,x,k;

  cin >> n >> x;

  vector<int> l(n + 1);

  l[0] = 0;

  for ( int i = 0; i < n; i++){
    cin >> k;
    l[i + 1] = l[i] + k;
  }

  int ans = 0;

  for (int i = 0; i <= n; i++){
    if (l[i] <= x){
      ans++;
    }
  }

  cout << ans << endl;
}
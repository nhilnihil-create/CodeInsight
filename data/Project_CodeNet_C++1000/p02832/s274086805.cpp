#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  int k = 1;
  rep(i,0,n) {
    int a;
    cin >> a;
    if (k == a) {
      k++;
    }
  }
  if (k == 1) {
    cout << -1 << endl;
    return 0;
  }
  cout << n-k+1 << endl;
  return 0;
}

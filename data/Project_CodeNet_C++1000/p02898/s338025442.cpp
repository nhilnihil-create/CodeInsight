#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  int cnt = 0;
  rep(i,n) {
    int x;
    cin >> x;
    if (k <= x) cnt++;
  }
  cout << cnt << endl;
}

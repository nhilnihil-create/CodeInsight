#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main(){
  int a,b;
  cin >> a >> b;
  int total = 1;
  int ans = 0;
  while (total < b) {
    // total += a -1とは意味合いが変わる
    total--;
    total += a;
    ans++;
  }
  cout << ans << endl;
}

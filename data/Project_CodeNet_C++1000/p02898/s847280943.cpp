#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k, ans;
  cin >> n >> k;
  ans = 0;
  rep(i,n){
    int a;
    cin >> a;
    if(a >= k){
      ans++;
    }
  }
  cout << ans;
  return 0;
}
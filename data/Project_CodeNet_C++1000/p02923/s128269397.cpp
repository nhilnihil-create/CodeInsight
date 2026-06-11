#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  std::vector<int> vec(n);
  rep(i,n) cin >> vec.at(i);
  int cnt = 0,ans = 0;
  rep(i,n-1) {
    if (vec.at(i) >= vec.at(i+1)) {
      cnt++;
      ans = max(ans,cnt);
      continue;
    }
    cnt = 0;
  }
  cout << ans << endl;
}

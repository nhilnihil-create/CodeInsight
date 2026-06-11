#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> w(n);
  int sum = 0;
  rep(i,n) {
    cin >> w[i];
    sum += w[i];
  }

  int ans = 10005;
  rep(i,n){
    if (i == 0) continue;
    int s1=0, s2;
    rep(j,i) s1 += w[j];
    s2 = sum - s1;
    ans = min(abs(s1-s2),ans);
  }
  cout << ans << endl;
}
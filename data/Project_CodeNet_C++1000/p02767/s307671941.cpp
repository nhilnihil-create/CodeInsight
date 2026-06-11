#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
#define _GLIBCXX_DEBUG

int main() {
  int n; cin >> n;
  vector<int> vec(n);
  rep(i,n) cin >> vec[i];
  int ans = 1e9;

  rep(i,101){
    int score = 0;
    rep(j,n) score += (vec[j]-i)*(vec[j]-i);
    if(score < ans) ans = score;
  }

  cout << ans << endl;
}

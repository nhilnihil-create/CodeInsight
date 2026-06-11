#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> d(k);
  vector<int> ans(n);
  int ans_sum = 0;
  rep(i, k){
    int m;
    cin >> m;
    rep(j, m){
      int a;
      cin >> a;
      ans[a-1] = 1;
    }
  }
  rep(i, n){
    if(ans[i] == 0) ans_sum++;
  }
  cout << ans_sum << endl;
}

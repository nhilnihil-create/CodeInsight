#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(x, y) x = max(x, y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int n, k; cin >> n >> k;
  int mx = 0;
  for(int i = 3; i <= n; i++){
    mx += i - 2;
  }
  if(k > mx){
    cout << -1 << endl;
    return 0;
  }
  vector<P> ans;
  for(int i = 2; i <= n; i++){
    ans.push_back(make_pair(1, i));
  }
  int cnt = 0;
  bool brk = false;
  for(int i = 2; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      if(cnt == mx - k){
        brk = true;
        break;
      }
      ans.push_back(make_pair(i, j));
      cnt++;
    }
    if(brk) break;
  }

  cout << ans.size() << endl;
  rep(i, ans.size()){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}

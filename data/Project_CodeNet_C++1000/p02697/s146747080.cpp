#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;

void solve(){
  int n, m; cin >> n >> m;
  vector<pair<int, int> > ans(m);
  if(n % 2 == 1){
    int j = 2;
    for(int i = 0; i < m; i++){
      ans[i].first = j;
      ans[i].second = n - j + 2;
      j++;
    }
  }
  else{
    int j, t = 0, x;
    if(n % 4 == 0){
      j = 2;
      x = 2;
    }
    else{
      j = 1;
      x = 1;
    }
    for(int i = 0; i < m; i++){
      if(j == n / 4 + 1) t++;
      ans[i].first = j;
      ans[i].second = n - j + x - t;
      j++;
    }
  }
  for(int i = 0; i < m; i++){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return;
}

int main(){
  solve();
  return 0;
}

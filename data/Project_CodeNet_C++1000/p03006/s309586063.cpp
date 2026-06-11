#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {  
  int N;
  cin >> N;
  vector<pair<int, int>> xy(N);
  for (int i = 0; i < N; i++) cin >> xy[i].first >> xy[i].second;
  sort(xy.begin(),xy.end());
 
  vector<bool> check(N);
  int ans = N;
  for (int i = 0; i < N-1; i++) {
    for (int j = i+1; j < N; j++) {
      int count = N;
      int p = xy[j].first - xy[i].first;
      int q = xy[j].second - xy[i].second;
      for (int k = 0; k < N-1; k++) {
        for (int l = k+1; l < N; l++) {
          int pp = xy[l].first - xy[k].first;
          int qq = xy[l].second - xy[k].second;
          if (p == pp && q == qq) count--;
        }
      }
      ans = min(ans,count);
    }
  }
  
  cout << ans << endl;      
}
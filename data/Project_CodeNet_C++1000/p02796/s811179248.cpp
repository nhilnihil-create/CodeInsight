#include<bits/stdc++.h>
using namespace std;
bool custom(pair<int, int> x, pair<int, int> y){
  if(x.second == y.second) return x.first < y.first;
  return x.second < y.second;
}
int main(){
  int n; cin >> n;
  vector<pair<int, int>> vp(n);
  for(int i = 0, x, l; i < n; ++i){
    cin >> x >> l;
    vp[i].first = x - l;
    vp[i].second = x + l;
  }
  sort(vp.begin(), vp.end(), custom);
  int ans = 0;
  int crr = vp[0].second;
  for(int i = 1; i < n ; ++i){
    if(crr > vp[i].first){
      ans++;
    }
    else crr = vp[i].second;
  }
  cout << n - ans << endl;
}
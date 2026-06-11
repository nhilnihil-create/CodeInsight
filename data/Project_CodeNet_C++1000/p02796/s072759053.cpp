#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<pair<int64_t,int64_t>> vec(n);
  rep(i,n) cin >> vec[i].first >> vec[i].second;
  vector<pair<int64_t,int64_t>> vec2(n);
  rep(i,n){
    vec2[i].first=vec[i].first-vec[i].second;
    vec2[i].second=vec[i].first+vec[i].second;
  }
  sort(vec2.begin(),vec2.end());
  int64_t ans=0;
  int64_t now=-1000000000;
  rep(i,n){
    if(now<=vec2[i].first){
      ans++;
      now=vec2[i].second;
    }
    else now=min(now,vec2[i].second);
  }
  cout << ans << endl;
  

}
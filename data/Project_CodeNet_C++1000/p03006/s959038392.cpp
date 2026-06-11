#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<P> xy(n);
  rep(i, n) cin >> xy[i].first >> xy[i].second;
  int sub = 0;
  rep(i, n) {
    for(int j = 0; j < n; ++j) {
      if(i == j) continue;
      ll p = xy[j].first - xy[i].first;
      ll q = xy[j].second - xy[i].second;
      
      int t = 0;
      rep(k, n) {
        rep(l, n) {
          if(k == l) continue;
          if(xy[k].first - xy[l].first == p && xy[k].second - xy[l].second == q) {
            ++t;
            break;
          }
        }
      }
      sub = max(sub, t);
    }
  }
  if(n == 1) sub = 0;
  
  cout << n - sub << endl;
}
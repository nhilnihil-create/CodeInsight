#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=998244353;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  vector<pii> v(n);
  rep(i,n) cin >> v[i].first >> v[i].second;
  int ans=n;
  rep(i,n)rep(j,n)if(i!=j){
    int dx=v[j].first-v[i].first;
    int dy=v[j].second-v[i].second;
    int sub=0;
    rep(i2,n)rep(j2,n)if(i2!=j2){
      int dx2=v[j2].first-v[i2].first;
      int dy2=v[j2].second-v[i2].second;
      if(dx2==dx&&dy2==dy) sub++;
    }
    chmin(ans,n-sub);
  }
  cout << ans << endl;
}
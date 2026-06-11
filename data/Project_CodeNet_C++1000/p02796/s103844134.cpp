#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int n;
  cin>>n;
  vin x(n),l(n);
  rep(i,0,n)cin>>x[i]>>l[i];
  vector<P> a(n);
  rep(i,0,n){
   a[i]=mp(x[i]+l[i],x[i]-l[i]); //後ろ　前
  }
  sort(all(a));
  int ans=0;
  int ude=-inf;
  rep(i,0,n){
    int w=a[i].first;
    int v=a[i].second;
    if(ude<=v){
      ude=w;
      ans++;
     // cout<<v<<endl;
    }
  }
  cout<<ans<<endl;
}
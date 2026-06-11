#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
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
  vector<P> ab(n);
  rep(i,0,n){
    int a;
    int b;
    cin>>a>>b;
    ab[i]=mp(a,b);
  }
  ///////
  sort(all(ab));
  map<P,int> cnt;
  rep(i,0,n-1){
    rep(j,i+1,n){
      int x=(ab[i].first-ab[j].first);
      int y=(ab[i].second-ab[j].second);
      cnt[mp(x,y)]++;
    }
  }
  
  int ma=0;
  for(auto v:cnt){
   chmax(ma,v.second); 
  }
  cout<<n-ma<<endl;
}
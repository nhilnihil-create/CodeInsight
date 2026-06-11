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
  int cnt[110000];
  int m=0;
  rep(i,0,n){
   int d;
    cin>>d;
    if(i==0&&d!=0||i!=0&&d==0){
      cout<<0<<endl;
      return 0;
    }
    cnt[d]++;
    m=max(m,d);
  }
  ll ans=1;
  rep(i,1,m+1){
    rep(j,0,cnt[i]){
     ans*=cnt[i-1]%998244353;
      ans%=998244353;
    }
   // cout<<ans<<endl;
   // cout<<ans<<endl;
  }
  cout<<ans%998244353<<endl;
  
}
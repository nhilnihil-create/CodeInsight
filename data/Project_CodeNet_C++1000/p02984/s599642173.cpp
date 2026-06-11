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
  vll a(n);
  rep(i,0,n){
    cin>>a[i];
  }
  ll x=0;
  rep(i,0,n){
    if(i%2==0) x+=a[i];
    else x-=a[i];
  }
  vll ans(n);
  ans[0]=x;
  cout<<ans[0]<<" ";
  rep(i,1,n){
   ans[i]=(a[i-1]-ans[i-1]/2)*2;
    cout<<ans[i]<<" ";
  }
 
}
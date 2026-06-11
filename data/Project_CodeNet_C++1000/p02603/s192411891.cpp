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
  vin a(n);
  rep(i,0,n)cin>>a[i];
  //////
  ll mny=1000;
  ll kabu=0;
  rep(i,0,n-1){
    mny+=kabu*a[i];
    kabu=0;
    
    
    if(a[i]<a[i+1]){
      kabu+=mny/a[i];
      mny-=a[i]*kabu;
    }
    else{
      continue;
    }
  }
  mny+=kabu*a[n-1];
  cout<<mny<<endl;
}
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  ll n,k; cin >> n >> k;
  vector<ll> a(n);
  ll r=0;
  rep(i,n){
    cin >> a[i];
    chmax(r,a[i]);
  }
  ll l=0;
  while(r-l!=1){
    ll mid=(l+r)/2;
    bool ok=0;
    int cnt=0;
    rep(i,n){
      cnt+=ceil((double)a[i]/mid)-1;
    }
    if(cnt<=k) ok=1;
    if(ok) r=mid;
    else l=mid;
  }
  cout << r << endl;
}
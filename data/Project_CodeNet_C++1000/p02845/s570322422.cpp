//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll MOD=1e9+7;
const int INF=1<<30;

int main(){
  ll ans=1;
  map<ll,ll> mp;
  mp[0]=3;
  ll N; cin >> N;
  vector<ll> a(N);
  rep(i,N) cin >> a[i];
  rep(i,N){
    ans*=mp[a[i]];
    ans%=MOD;
    mp[a[i]]--; mp[a[i]+1]++;
  }
  cout << ans << endl;
}
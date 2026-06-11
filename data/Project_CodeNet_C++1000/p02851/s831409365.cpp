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
  int N,K;
  cin >> N >> K;
  vector<ll> a(N);
  rep(i,N) cin >> a[i];
  vector<ll> s(N+1);
  s[0]=0;
  rep(i,N) s[i+1]=s[i]+a[i];
  vector<ll> t(N+1);
  rep(i,N+1) t[i]=(s[i]-i)%K;
  map<ll,ll> mp;
  ll ans=0;
  rep(i,N+1){
    if(i>=K) mp[t[i-K]]--;
    ans+=mp[t[i]];
    mp[t[i]]++;
  }
  cout << ans << endl;
}
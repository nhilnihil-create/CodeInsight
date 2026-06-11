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
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n,K; cin >> n >> K;
  vector<ll> a(n);
  ll sum=0;
  rep(i,n){
    cin >> a[i];
    sum+=a[i];
  }
  ll ans=0;
  for(int i=1;i<=sqrt(sum);i++){
    if(sum%i!=0) continue;
    vector<ll> p={i,sum/i};
    rep(k,2){
      vector<ll> b=a;
      rep(j,n){
        b[j]%=p[k];
      }
      sort(all(b));
      vector<ll> s(n+1);
      s[0]=0;
      rep(j,n){
        s[j+1]=s[j]+b[j];
      }
      
      rep(j,n+1){
        ll mns=s[j];
        ll pls=p[k]*(n-j)-(s[n]-s[j]);
        if(mns==pls&&pls<=K) chmax(ans,p[k]);
      }
    }
  }
  cout << ans << endl;
}
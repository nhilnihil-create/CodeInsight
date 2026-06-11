#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

template <class T>
void cout_vec2(const vector<vector<T>> &vec){
  rep(i,vec.size()){
    rep(j,vec[i].size()){
      cout<<vec[i][j]<<' ';
    }
    cout<<endl;
  }
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<int> p(n),ind(n);
  rep(i,n){
    cin>>p[i];
    p[i]--;
    ind[p[i]]=i;
  }
  multiset<int> cnt;
  cnt.insert(-1),cnt.insert(-1),cnt.insert(n),cnt.insert(n);
  ll ans=0;
  ll a,b,c,d,now;
  for(ll i=n-1;i>=0;i--){
    cnt.insert(ind[i]);
    auto itr=cnt.find(ind[i]);
    now=ind[i];
    itr++,a=*itr;
    itr++,b=*itr;
    itr--,itr--,itr--,c=*itr;
    itr--,d=*itr;
    ans+=(i+1)*((b-a)*(now-c)+(a-now)*(c-d));
  }
  cout<<ans<<endl;
}
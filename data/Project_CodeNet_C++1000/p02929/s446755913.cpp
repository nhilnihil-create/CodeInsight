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

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  string s;
  cin>>s;
  ll ans=0;
  int cnt=0;
  rep(i,2*n){
    if(i%2==0){
      if(s[i]=='B') s[i]='W';
      else s[i]='B';
    }
    if(s[i]=='B') cnt++;
  }
  if(cnt!=n){
    cout<<ans<<endl;
    return 0;
  }
  ans=1;
  cnt=0;
  rep(i,2*n){
    if(s[i]=='W') cnt++;
    else{
      (ans*=cnt)%=mod;
      cnt--;
    }
  }
  FOR(i,1,n+1){
    (ans*=i)%=mod;
  }
  cout<<ans<<endl;
}
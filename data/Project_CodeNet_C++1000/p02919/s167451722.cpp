#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define MOD 1000000007;

int main(){
  ll n,ans=0;cin>>n;
  vll p(n),basyo(n+1);
  rep(i,0,n){cin>>p[i];p[i]--;basyo[p[i]]=i;}
  set<ll> s;
  for(int i=n-1;i>=0;i--){
    int idx=basyo[i];
    ll c=0;vll l(2,-1),r(2,n);
    s.insert(idx);
    auto it=s.find(idx);
    rep(j,0,2){
      if(it==s.begin()){break;}
      it--;
      l[j]=*it;
    }
    it=s.find(idx);
    rep(j,0,2){
      it++;
      if(it==s.end()){break;}
      r[j]=*it;
    }
    ll l1=idx-l[0],l2=l[0]-l[1],r1=r[1]-r[0],r2=r[0]-idx;
    c=l1*r1+l2*r2;
    ans+=c*(i+1);
  }
  cout<<ans<<endl;
}



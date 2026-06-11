#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;


int main(){
  ll n;cin>>n;
  vll a(n);
  set<ll> s;
  rep(i,0,n){
    cin>>a[i];
    s.insert(a[i]);
  }
  if(s.size()>3){
    cout<<"No"<<endl;return 0;
  }
  if(s.size()==3){
    vll b(3);
    auto it=s.begin();
    rep(i,0,3){
      b[i]=*it;
      it++;
    }
    ll x=b[0]^b[1]^b[2];
    if(x!=0){
      cout<<"No"<<endl;return 0;
    }
    vll c(3,0);
    rep(i,0,n){
      rep(j,0,3){
        if(a[i]==b[j])c[j]++;
      }
    }
    if(!(c[0]==c[1]&&c[1]==c[2])){
      cout<<"No"<<endl;return 0;
    }
  }
  else if(s.size()==2){
    auto it=s.begin();
    if(*it!=0){
      cout<<"No"<<endl;return 0;
    }
    ll x=0;
    rep(i,0,n){
      if(a[i]==0)x++;
    }
    if(x!=n/3||n%3){
      cout<<"No"<<endl;return 0;
    }
  }
  else{
    
    if(*(s.begin())!=0){
      cout<<"No"<<endl;return 0;
    }
  }
  cout<<"Yes"<<endl;
  
}



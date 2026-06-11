#include <bits/stdc++.h>
 
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
const ll inf=1e9;
const int MAX = 510000;
const ll MOD = 998244353;

inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

int main(){
  ll s;cin>>s;
  ll x=s%1000000000,y=s/1000000000;
  if(y==1000000000){
    cout<<"0 0 1000000000 0 0 1000000000"<<endl;return 0;
  }
  cout<<"0 0 1000000000 1 "<<1000000000-x<<" "<<y+1<<endl;
}
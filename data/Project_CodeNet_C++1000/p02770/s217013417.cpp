#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
typedef long long ll;

int main(){
  ll k,q;
  cin>>k>>q;
  vector<ll>d(5009);
  rep(i,k)cin>>d[i];
  rep(i,q){
    ll n,x,m;
    cin>>n>>x>>m;
    vector<ll>nd;
    nd=d;
    ll cnt=0;
    rep(i,k){
      nd[i]%=m;
      if(nd[i]==0)cnt++;
    }
    x%=m;
    ll ln=(n-1)/k;
    ll rn=(n-1)%k;
    cnt*=ln;
    ll asum=0,bsum=0;
    rep(i,k){
      asum+=nd[i];
      if(i<rn){
        bsum+=nd[i];
        if(nd[i]==0)cnt++;
      }
    }
    ll last=x+asum*ln+bsum;
    cout<<n-1-last/m-cnt<<endl;
  }
  return(0);
}

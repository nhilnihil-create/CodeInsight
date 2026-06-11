#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin>>n;
  vector<ll> a(n+5);
  ll sum=0;
  rep(i,n){
    cin>>a[i];
    sum^=a[i];
  }
  //cout<<sum<<endl;

  //sumが１のところを０にする
  rep(i,n)a[i]&=~sum;
  vector<ll> t(n);

  //吐き出し
  ll now=0;
  for(ll i=60;i>=0;i--){
    ll j=now;
    for(;j<n;j++){
      if (1 & a[j]>>i){
        swap(a[now],a[j]);
  //      cout<<now<<"now"<<a[now]<<'a'<<endl;
      //  cout<<i<<' '<<a[now]<<endl;
        now++;
      //  cout<<now<<endl;
        break;
      }
    }

    if (j==n)continue;
    t[now-1]=i;
    rep(j,n){
      if (j==now-1)continue;
      if (1 & a[j]>>i){
        a[j]^=a[now-1];
      //  cout<<a[j]<<'j'<<a[now-1]<<endl;
      }
    }
  }

  //一つずつくらいを試す
  ll cnt=0;
  ll ans=cnt;
  bool ok=false;
   for(ll i=60; i>=0;i--){
    ll cntpre=cnt;
    cnt^=(1ll<<i);
    ll temp=cnt;
    //cout<<cnt<<endl;
    rep(j,now){
    //  cout<<t[j]<<endl;
      if((temp>>t[j])&1) {
        temp^=a[j];
      //  cout<<cnt<<'c'<<t[j]<<"tj"<<temp<<'t'<<a[j]<<'a'<<endl;
      }

    }
    if ((temp&cnt)!=0){
    //  cout<<"no"<<endl;
      cnt=cntpre;
    }
  //  cout<<temp<<'t'<<cnt<<'c'<<endl;

  }
  ans=cnt*2;
  ans+=sum;
  cout<<ans;

}


#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;


int main() {
  ll n,k;
  cin>>n>>k;

  vector<ll>g(n);
  vector<ll>c(n);
  vector<ll>u(n,-1);
  ll Ans=-INF;

  rep(i,n){
    ll p;
    cin>>p;
    p--;
    g[i]=p;
  }
  rep(i,n)cin>>c[i];

  rep(i,n){
    //cout<<i<<endl;
    ll ans=-INF;
  //  if(u[i]==1)continue;

    vector<ll> v;
    ll now=i;
    ll cnt=0;
    ll s=0;
    u[now]=1;

    while(1){
      s+=c[now];
  now=g[now];
  v.push_back(c[now]);
//cout<<"c"<<c[now]<<endl;
      cnt+=1;
      u[now]=1;
    if (now==i)break;
    }


    vector<ll> sv(10005,0);
    rep(j,v.size()){
      sv[j+1]=sv[j]+v[j];
    }
    rep(j,v.size()){
      sv[v.size()+j+1]=sv[v.size()+j]+v[j];
    }
    ll t=k/cnt;
    t--;
    ll q=k-(t*cnt);
  //  cout<<"s"<<s<<endl;
    //cout<<"cnt"<<cnt<<endl;

    if(s>0){
    //  cout<<"q"<<q<<endl;

      rep(j,q){
        ans=max(ans,sv[j+1]);
    //    cout<<"sv"<<sv[j+1]<<endl;
      }
      ans+=t*s;
    }

    else{
    //  ll q=k-(t*cnt);
    rep(j,q){
      ans=max(ans,sv[j+1]);
    //  cout<<"sv"<<sv[j+1]<<endl;

      }
    }
    Ans=max(Ans,ans);

  }

cout<<Ans;


}

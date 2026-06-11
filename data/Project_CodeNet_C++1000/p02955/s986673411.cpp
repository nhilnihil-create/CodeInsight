#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n-1); i >= 0; i--)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

map<ll,ll>prime_factor(int m)
{
  map<ll,ll>res;
  ll sqrm=sqrt(m)+1;
  for(int i=2;i<sqrm+1;i++)
  {
    while(m%i==0){res[i]++;m/=i;}
    if(m==1)break;
  }
  if(m>1)res[m]++;
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,k;cin>>n>>k;
  vector<ll>a(n);
  ll sa=0;
  rep(i,n){
    cin>>a[i];
    sa+=a[i];
  }

  auto check=[&](ll num){
    map<ll,ll>cnt;
    rep(i,n){
      cnt[a[i]%num]++;
    }
    vector<pair<ll,ll>>cn;
    for(auto tp:cnt){
      cn.push_back(tp);
    }
    ll l=cn.size();
    ll ts=0;
    rep(i,l){
      if(2*cn[i].first>num)cn[i].first-=num;
      ts+=cn[i].first*cn[i].second;
    }
    ts/=num;
    sort(all(cn),[&](pair<ll,ll> a,pair<ll,ll> b){return abs(abs(2*a.first)-num)<abs(abs(2*b.first)-num);});
    ll tk=0;
    auto tcn=cn;
    rep(i,l)tcn[i].second=0;
    if(ts<0){
      rep(i,l){
        if(cn[i].first>0)continue;
        ll td=min(-ts,cn[i].second);
        ts+=td;
        cn[i].second-=td;
        tcn[i].first=cn[i].first+num;
        tcn[i].second=td;

        if(ts==0){
          break;
        }
      }
    }
    else if(ts>0){
      rep(i,l){
        if(cn[i].first<0)continue;
        ll td=min(ts,cn[i].second);
        ts-=td;
        cn[i].second-=td;
        tcn[i].first=cn[i].first-num;
        tcn[i].second=td;

        if(ts==0){
          break;
        }
      }
    }
    rep(i,l){
      tk+=abs(cn[i].first)*cn[i].second+abs(tcn[i].first)*tcn[i].second;
      ////cout<<cn[i].first<<" "<<cn[i].second<<" "<<tcn[i].second<<endl;
    }
    //cout<<"num "<<num<<" tk "<<tk<<endl;
    return tk<=k*2;

  };
  vector<ll>so;
  //cout<<sa<<endl;
  for(ll i=1;i*i<=sa;i++){
    if(sa%i==0){
      //cout<<i<<sa%i<<endl;
      so.push_back(i);
      if(i*i!=sa){
        so.push_back(sa/i);
      }
    }
  }
  sort(all(so));
  rrep(i,so.size()){
    ll res=so[i];
    if(check(res)){
      cout<<res<<endl;
      return 0;
    }
  }



  return 0;

}

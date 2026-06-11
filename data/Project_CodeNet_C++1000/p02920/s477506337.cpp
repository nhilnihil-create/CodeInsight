#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vec=vector<ll>;
using mat=vector<vec>;
#define For(i,a,b) for(i=a;i<b;i++)
#define bFor(i,a,b) for(i=a;i>=b;i--)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N-1,0)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define mod 1000000007
#define endl "\n"
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}while(0)
using datas=pair<ll,ll>;
using tdata=pair<ll,datas>;

int main(){
  ll i,j=0,N,K,x;
  cin>>N;
  K=pow(2,N);
  multiset<ll> se;
  rep(i,K){
    cin>>x;
    se.insert(-x);
    j=max(j,x);
  }
  K=1;
  vec v(1,-j);
  se.erase(-j);
  rep(i,N){
    v.resize(K*2);
    rep(j,K){
      auto itr=se.upper_bound(v[j]);
      if(itr==se.end()){
        cout<<"No"<<endl;
        return 0;
      }
      v[j+K]=*itr;
      se.erase(itr);
    }
    K*=2;
  }
  cout<<"Yes"<<endl;
  return 0;
}
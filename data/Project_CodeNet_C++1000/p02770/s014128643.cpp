#include "bits/stdc++.h"
using namespace std;
#define REP(i, n) for(ll i = 0;i < n;i++)
#define ll long long
#define MOD 1000000007
#define llMAX 9223372036854775807
#define llMIN -9223372036854775808
using vi = vector<ll>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける

ll k,q;

int main(){
  ll ans=0;
  cin >> k>>q;
  vi d(k),dm(k),n(q),x(q),m(q);
  REP(i,k) cin>>d[i];

  REP(i,q){
    cin>>n[i]>>x[i]>>m[i];
  }


  REP(i,q){

    ll zc=0;
    ll zc2=0;
    ll smal=0;
    ll sm=0;
    ll nm=(n[i]-1)%k;
    REP(j,k){
      dm[j]=d[j]%m[i];
      if (dm[j]==0){
        zc++;
        if (j<nm)zc2++;
      }
      smal+=dm[j];
    }
    x[i]%=m[i];
    ll maxnum=x[i]+((n[i]-1)/k)*smal;
    
    REP(j,nm){
      sm+=dm[j];
    }
    maxnum+=sm;
    ans=n[i]-1;
    ll koe=maxnum/m[i];
    ans-=koe;
    ans-=zc*((n[i]-1)/k);
    ans-=zc2;
    cout<<ans<<endl;

    
  }


  //cout<<ans<<endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll n,m,k;
vector<ll> sa,sb;

bool isok(ll i,ll j){
  if(sb[j]<=k-sa[i])return true;
  else return false;
}

    
int nibutan(ll i){
  int ok=0,ng=m+1;
  while(ng-ok>1){
    ll naka=(ng+ok)/2;
    if(isok(i,naka))ok=naka;
    else{
      ng=naka;
    }
  }
    return ok+i;
  }
    
 int main(){
   cin>>n>>m>>k;
   sa.resize(n+1);
   sb.resize(m+1);
   sa[0]=0, sb[0]=0;
   for(ll i=0;i<n;i++){
     int a;
     cin>>a;
   sa[i+1]=sa[i]+a;
   }
   for(ll j=0;j<m;j++){
     int b;
     cin>>b;
    sb[j+1]=sb[j]+b;
   }
   ll ans=0;
   for(ll i=0;i<=n;i++){
     if(sa[i]<=k){
     ll ima=nibutan(i);
     ans=max(ans, ima);
     }
   }
cout<<ans<<endl;
}
       
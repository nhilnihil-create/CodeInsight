#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll d[5005]={0},k;
ll solve(ll x,ll n,ll mod){
  ll sd[5005],ad[5005]={0};
  n--;
  for(int i=0;i<k;i++) sd[i]=d[i]%mod;
  for(int i=0;i<k;i++) ad[i]=n/k;
  for(int i=0;i<(n%k);i++) ad[i]++;
  x%=mod;
  ll fst=x,lst=x,res=n;
  for(int i=0;i<k;i++) lst+=sd[i]*ad[i];
  res-=((lst/mod)-(fst/mod));
  for(int i=0;i<k;i++){
    if(sd[i]==0) res-=ad[i];
  }
  return res;
}
int main(){
  ll q;
  cin>>k>>q;
  for(int i=0;i<k;i++) cin>>d[i];
  for(int i=0;i<q;i++){
    ll n,x,m;
    cin>>n>>x>>m;
    cout<<solve(x,n,m)<<endl;
  }
}

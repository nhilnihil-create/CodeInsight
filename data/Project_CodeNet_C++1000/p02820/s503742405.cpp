#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int main() {
  int n,k;
  cin>>n>>k;
  int r,s,p;
  cin>>r>>s>>p;
  string t;
  cin>>t;
  ll ans=0;
  for(int i=0;i<min(n,k);i++){
    int cnt=0;
    for(int j=i;j<n;j+=k){
      if(j==i){
        if(t[j]=='r')ans+=p;
        else if(t[j]=='s')ans+=r;
        else ans+=s;
        cnt++;
      }
      else{
        if(t[j]!=t[j-k]){
          if(t[j]=='r')ans+=p;
          else if(t[j]=='s')ans+=r;
          else ans+=s;
          cnt=1;
        }
        else{
          if(cnt%2==0){
            if(t[j]=='r')ans+=p;
            else if(t[j]=='s')ans+=r;
            else ans+=s;
          }
          cnt++;
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}


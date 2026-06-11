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
  int n;
  cin>>n;
  ll a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  ll money=1000,stock=0;
  ll sa[n-1];
  for(int i=0;i<n-1;i++){
    sa[i]=a[i+1]-a[i];
  }
  for(int i=0;i<n-1;i++){
    if(sa[i]==0) continue;
    if(sa[i]<0) {
      money+=stock*a[i];
      stock=0;
    }
    if(sa[i]>0){
      ll temp=money;
      money=temp%a[i];
      stock+=temp/a[i];
    }
  }
  money+=stock*a[n-1];
  cout<<money<<endl;
  return 0;
}

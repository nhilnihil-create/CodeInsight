#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using pll=pair<ll,ll>;

const ll MOD=1000000007;

ll abs1(ll a){
  if(a>=0)return a;
  else return -a;
}

ll pow1(ll a,ll b,ll p=LLONG_MAX){
  ll ret=1;
  while(b!=0){
    if((b&1)==1){
      ret*=a;
    }
    a*=a;
    if(a>=p)a%=p;
    b=b>>1;
  }
  return ret;
}

int digit(ll a,ll b){
  int i=0;
  while(a!=0){
    a/=b;
    i++;
  }
  return i;
}

int ord(ll a,ll p){
  int i=0;
  while(a%p==0){
    a/=p;
    i++;
  }
  return i;
}

ll gcd1(ll a,ll b){
  if(a==0 && b==0)return 0;
  ll n;
  while(a%b!=0){
    n=a%b;
    a=b;
    b=n;
  }
  return b;
}

ll solveLinear(ll n,ll m,ll c){
  if(n==0 && m==0)return 0;
  ll a[100],b[100];
  a[0]=n;b[0]=m;
  int i=1;
  while(b[i-1]!=0){
    a[i]=b[i-1];
    b[i]=a[i-1]%b[i-1];
    i++;
  }
  n=i;
  if(c%a[n-1]!=0){
    return 0;
  }
  ll x=c/a[n-1],y=0;
  for(i=1;i<n;i++){
    ll cnt=x;
    x=y;
    y=cnt-(a[n-i-1]/b[n-i-1])*y;
  }
  return x;
}

ll modRev(ll a,ll p=MOD){
  a%=p;
  ll n=solveLinear(a,p,1);
  n%=p;
  if(n<0)return n+p;
  return n;
}

ll fact(ll n,ll p=MOD){
  if(n<0)return 0;
  int i;
  ll ret=1;
  for(i=0;i<n;i++){
    ret=ret*(i+1);
    if(ret>=p)ret%=p;
  }
  return ret;
}

ll perm(ll n,ll k,ll p=MOD){
  if(n<0 || k<0 || n<k)return 0;
  int i;
  ll ret=1;
  for(i=0;i<k;i++){
    ret=ret*(n-i);
    if(ret>=p)ret%=p;
  }
  return ret;
}

ll binom(ll n,ll k,ll p=MOD){
  if(n<0 || k<0 || n<k)return 0;
  int i;
  ll ret=1,fact=1;
  for(i=0;i<k;i++){
    ret=ret*(n-i);
    fact*=i+1;
    if(ret>=p)ret%=p;
    if(fact>=p)fact%=p;
  }
  return (ret*modRev(fact))%p;
}

int main(){
  int i,j,k;ll cnt=0;
  ll n;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  ll sum=0;
  for(i=0;i<n;i++)sum+=a[i];
  if(a[0]>=0){
    cout<<sum-2*a[0]<<endl;
    for(i=1;i<n-1;i++){
      cout<<a[0]<<" "<<a[i]<<endl;
      a[0]-=a[i];
    }
    cout<<a[n-1]<<" "<<a[0]<<endl;
    return 0;
  }
  if(a[n-1]<=0){
    cout<<2*a[n-1]-sum<<endl;
    for(i=0;i<n-1;i++){
      cout<<a[n-1]<<" "<<a[i]<<endl;
      a[n-1]-=a[i];
    }
    return 0;
  }
  sum=0;
  for(i=0;i<n;i++)sum+=abs1(a[i]);
  cout<<sum<<endl;
  for(i=0;i<n-1;i++){
    if(a[i]<0 && 0<=a[i+1]){
      cnt=i;
    }
    if(0<=a[i]){
      cout<<a[0]<<" "<<a[i]<<endl;
      a[0]-=a[i];
    }
  }
  for(i=0;i<=cnt;i++){
    cout<<a[n-1]<<" "<<a[i]<<endl;
    a[n-1]-=a[i];
  }
  return 0;
}

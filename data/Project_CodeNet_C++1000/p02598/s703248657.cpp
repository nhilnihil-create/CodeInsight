#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define per(i,s,n) for(int i=n-1;i>=s;i--)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef long double ld;
typedef pair<ld, ll> P;

void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001000000;
const ll mod=1000000007;


int main(){
  ll n,k;
  cin>>n>>k;
  ll a[n];
  ll m=0;
  ll now=0;
  rep(i,n){
    cin>>a[i];
    now+=a[i];
    m=max(m,a[i]);
  }
 
  ll nl,nh;
  nl=1;
  nh=m;
  ll nm;
  
  while(nh-nl>0){
    nm=(nl+nh)/2;
    ll cnt=0;
    rep(i,n){
      if(a[i]%nm==0){
        cnt+=a[i]/nm;
        cnt--;
      }
      else{
        cnt+=a[i]/nm;
      }
    }
    if(cnt>k){
      nl=nm+1;
    }
    else{
      nh=nm;
    }
  }
  cout<<nh<<endl;
}


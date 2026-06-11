#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vec=vector<ll>;
#define For(i,a,b) for(i=a;i<(ll)b;i++)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define all(v) (v).begin(),(v).end()
#define vsort(v) sort(all(v))
#define endl "\n"
#define pb push_back
ll N,S;
vec v,sum;
int judge(ll K,ll x){
  ll i=lower_bound(all(v),x)-v.begin();
  K-=S-i;
  if(!i||K<=0)return 1;
  if(sum[i-1]/K>=x){
    return 1;
  }
  return 0;
}
int main(){
  ll i,N,cnt=1;
  cin>>N;
  vec a(N);
  rep(i,N)cin>>a[i];
  vsort(a);
  rep1(i,N){
    if(a[i]==a[i-1]){
      cnt++;
    }else{
      v.pb(cnt);
      cnt=1;
    }
  }
  v.pb(cnt);
  vsort(v);
  S=v.size();
  sum.resize(S);
  sum[0]=v[0];
  rep1(i,S)sum[i]=sum[i-1]+v[i];
  rep1(i,N+1){
    if(i>S){
      cout<<0<<endl;
      continue;
    }
    ll ng=N/i+1,ok=0,mid;
    while(ng-ok>1){
      mid=(ok+ng)/2;
      if(judge(i,mid)){
        ok=mid;
      }else{
        ng=mid;
      }
    }
    cout<<ok<<endl;
  }
  return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll ans=0;
  int n;
  cin>>n;
  if(n==0){
    int a;
    cin>>a;
    if(a==1){
      cout<<1<<endl;
      return 0;
    }
    cout<<-1<<endl;
    return 0;
  }
  if(n==1){
    int a,b;
    cin>>a>>b;
    if(a>=1){
      cout<<-1<<endl;
      return 0;
    }
    if(b<=2){
      cout<<1+b<<endl;
      return 0;
    }
    cout<<-1<<endl;
    return 0;
  }
  ll now=1;
  ll vec[n];
  ll vecb[n+1];
  for(int i=0;i<n+1;i++){
    cin>>vecb[i];
  }
  for(int i=0;i<n+1;i++){
    ll x=vecb[i];
    if(i==0&&x==1){
      cout<<-1<<endl;
      return 0;
    }
    vec[i]=now;
    now-=x;
    if(now<0){
      cout<<-1<<endl;
      return 0;
    }
    if(now==0){
      if(i!=n){
        cout<<-1<<endl;
        return 0;
      }
    }
    if(now>1e17||now<0){
      now=1e20+1;
    }
    else{
      now*=2;
    }
  }
  ll sum=0;
  for(int i=n;i>=0;i--){
    sum+=vecb[i];
    ans+=min(sum,vec[i]);
  }
  cout<<ans<<endl;
}
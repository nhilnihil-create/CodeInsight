#include<bits/stdc++.h>
#define rep(i,a,n) for(ll i=a;i<n;i++)
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin>>n;
  ll a[n],num[n+1];
  rep(i,0,n+1)num[i]=0;
  rep(i,0,n){
    cin>>a[i];
    num[a[i]]++;
  }
  ll sum=0;
  rep(i,1,n+1){
    if(num[i]>=2){
      rep(j,1,num[i])sum+=j;
    }
  }
  rep(i,0,n){
    if(a[i])cout<<sum-num[a[i]]+1<<endl;
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n,sum=0,tempsum=0;
  cin>>n;
  vector<ll>v1(n);
  for(ll i=0;i<n;i++){
    cin>>v1[i];
    sum+=v1[i];
    if(i%2==1){
      tempsum+=v1[i]*2;
    }
  }
  ll x1=sum-tempsum;
  cout<<x1<<" ";
  for(ll j=0;j<n-1;j++){
    ll y=v1[j]*2-x1;
    x1=y;
    cout<<x1<<" ";
  }

  
}
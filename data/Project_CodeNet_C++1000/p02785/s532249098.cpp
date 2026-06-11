 #include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
  ll n,k,ans=0;
  cin>>n>>k;
  ll h[n];
  for(ll i=0;i<n;i++){
    cin>>h[i];
  }
  sort(h,h+n);
  reverse(h,h+n);
  
  for(ll i=0;i<n;i++){
    if(i<k){
      continue;
    }else{
      ans = ans + h[i];
    }
  }
  cout<<ans<<endl;
}
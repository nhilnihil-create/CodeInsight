#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
ll pow(ll a,ll b){
  if(b==0){
    return 1;
  }else if(b%2==0){
    return(pow(a*a,b/2));
  }else{
    return(a*pow(a,b-1));
  }
}
ll gcd(ll a,ll b) {
  if(a%b==0){
    return(b);
  }else{
    return(gcd(b,a%b));
  }
}
ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}
ll log2(ll a,ll count){
  if(a%2==0){a/=2;count++;log2(a,count);}
  else{return count;}
}
int main(){
  ll N,M,ans=1;
  cin>>N>>M;
  vector<ll> a(N);
  for(ll i=0;i<N;i++){
    ll d;
    cin>>d;
    a.at(i)=d/2;
    ll memo=ans;
    ans=lcm(ans,a.at(i));
    if(i>=1){if(log2(a.at(i),0)!=log2(a.at(i-1),0)){cout<<0<<endl;return 0;}}
    if(ans>M){cout<<0<<endl;return 0;}
    else{continue;}
  }
  cout<<(M-ans)/(2*ans)+1<<endl;
}
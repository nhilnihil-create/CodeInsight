#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll gcd(ll a, ll b){
  if(b == 0){
    return a;
  }
  else{
    return gcd(b,(a%b));
  }
}
ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}
ll mpower(ll a,ll b,ll c){
  int z;
  if(b==0){
    z=1;
    z%=c;
    return z;
  }
  if(b==1){
    z=a;
    z%=c;
    return z;
  }
  else{
    return (((mpower(a,b/2,c))*(mpower(a,b/2,c))%c)*mpower(a,b%2,c)%c);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  int vec[n];
  string s;
  cin>>s;
  for(int i=0;i<n;i++){
    if(i>=s.size()){
      vec[i]=1;
      continue;
    }
    if(s.at(i)=='1'){
      vec[i]=1;
    }
    if(s.at(i)=='2'){
      vec[i]=2;
    }
    if(s.at(i)=='3'){
      vec[i]=3;
    }
  }
  int ans=0;
  while(n>4000){
    if(n%2==0){
      for(int i=0;i<n/2;i++){
        vec[i]=abs(vec[2*i]-vec[2*i+1]);
      }
      n/=2;
      ans++;
      continue;
    }
    if(n%2==1){
      for(int i=0;i<n-1;i++){
        vec[i]=abs(vec[i]-vec[i+1]);
      }
      n-=1;
      ans++;
      continue;
    }
  }
  while(n>1){
    for(int i=0;i<n-1;i++){
      vec[i]=abs(vec[i]-vec[i+1]);
    }
    n-=1;
  }
  //cout<<ans<<endl;
  cout<<vec[0]<<endl;
}
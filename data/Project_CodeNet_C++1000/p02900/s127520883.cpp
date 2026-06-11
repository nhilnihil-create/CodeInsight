#include<bits/stdc++.h>
using namespace std;

int64_t gcd(int64_t a,int64_t b){
  int64_t g=max(a,b),l=min(a,b),n=l;
  while(g%l!=0){
    n=l;
    l=g%l;
    g=n;
  }
  return l;
}

int main(){
  int64_t a,b;
  cin >> a >> b;
  int64_t n=gcd(a,b);
  int ans=1;
  for(int64_t i=2;i*i<=n;i++){
    if(n%i==0){
      ans++;
      while(n%i==0)
      n/=i;
    }
  }
  if(n!=1)ans++;
  cout << ans << endl;
  return 0;
}
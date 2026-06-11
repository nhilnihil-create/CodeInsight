#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int64_t modpow(int64_t a,int64_t n,int64_t m){
  int64_t res=1;
  while(n>0){
    if(n&1) res=res*a%m;
    a=a*a%m;
    n>>=1;
  }
  return res;
}

int64_t modinv(int64_t a,int64_t p){
  int64_t res=modpow(a,p-2,p);
  return res;
}

int64_t combi(int64_t n,int64_t r,int64_t p){
  int64_t res;
  int64_t a=1,b=1;
  for(int i=n-r+1;i<=n;i++){
    a=a*i%p;
  }
  for(int i=1;i<=r;i++){
    b=b*i%p;
  }
  res=a*modinv(b,p)%p;
  return res;
}

int main() {
  int n,a,b;
  int big=1000000007;
  cin >> n >> a >> b;
  int64_t ans=modpow(2,n,big);
  ans--;
  ans=(ans-combi(n,a,big)+big-combi(n,b,big)+big)%big;
  cout << ans;
}

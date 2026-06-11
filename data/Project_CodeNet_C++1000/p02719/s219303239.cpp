#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  ll n,k;
  cin >> n >> k;
  if(n<n-k){
    printf("%lld",n);
    return 0;
  }
  ll d = n%k;
  d = min(d,abs(d-k));
  printf("%lld",d);
  return 0;
}
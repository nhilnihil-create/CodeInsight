#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool prime(ll n){
  bool x = true;
  for(ll k=2;k*k<=n;k++)
    if(n%k==0) x = false;
  if(n==1) x = false;
  return x;
}

int main(){
  ll N,i,ans;
  ans = 0;
  cin >> N;
  for(i=2;i*i<=N;i++)
    if(N%i==0 && prime(i)){
      ll count = 0;
      ll a = 0;
      while(N%i==0){
        N /= i;
        count++;
      }
      for(ll j = 1;j<=100;j++){
        a += j;
        if(a > count) break;
        ans++;
      }
    }
  if(prime(N)) ans++;
  cout << ans << endl;
}


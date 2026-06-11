#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a,ll b){
  if(b==0){
    return a;
  }
  else{
    return gcd(b,a%b);
  }
}

ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}

int main(){
  ll N,M;
  cin >> N >> M;
  vector<ll> B(N);
  for(ll i=0;i<N;i++){
    ll a;
    cin >> a;
    if(a%2==1){
      cout << 0 << endl;
      return 0;
    }
    B[i]=a/2;
  }
  ll count=0;
  ll b=B[0];
  while(b%2==0){
    b=b/2;
    count++;
  }
  for(ll i=1;i<N;i++){
    ll c=0;
    ll d=B[i];
    while(d%2==0){
      d=d/2;
      c++;
    }
    if(count!=c){
      cout << 0 << endl;
      return 0;
    }
  }
  ll T=1;
  for(ll i=0;i<N;i++){
    T=lcm(T,B[i]);
  }
  ll kaisuu=M/T;
  if(kaisuu%2==0){
    cout << kaisuu/2 << endl;
  }
  else{
    cout << (kaisuu+1)/2 << endl;
  }
}
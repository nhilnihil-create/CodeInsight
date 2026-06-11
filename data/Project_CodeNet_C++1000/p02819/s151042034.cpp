#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

bool ptest(ll n){
  bool is_prime=true;
  if(n==1)is_prime=false;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      is_prime=false;
      break;
    }
  }
  return is_prime;
}

int main(){

  ll x;
  cin >> x;

  while(!ptest(x)){
    x++;
  }

  cout << x << endl;


}
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>


long long int mod(long long int x, long long int m);
long long int mod_inverse(long long int x, long long int m);
long long int mod_inverse_Fermat(long long int x, long long int m);
long long int fast_power(long long int x, long long int n, long long int m);
long long int euclid_extended(long long int a, long long int b, long long int &x, long long int &y);


using ll = long long int;
using namespace std;

ll MOD = 1e9+7;

int main(){

  ll N, K;
  cin >> N >> K;

  // make prime list
  vector<ll> prime(K+1);
  prime[0] = 0;
  prime[1] = 0;
  for(ll i = 2; i <= K; i++){
    prime[i] = 1;
  }
  for(ll i = 2; i <= K; i++){
    if(prime[i] == 1){
      for(ll j = 2; i*j <= K; j++){
        prime[i*j] = 0;
      }
    }
  }
  vector<ll> prime_list;
  for(ll i = 0; i <= K; i++){
    if(prime[i] == 1){
      prime_list.push_back(i);
    }
  }
  ll Nprime = prime_list.size();

  cerr << "prime list is made";

  cerr << "Nprime: " << Nprime << endl;
  /*for(ll i = 0; i < Nprime; i++){
    cerr << prime_list[i] << " ";
  }cerr << endl;*/

  // solve problem
  ll ans = 0;
  vector<ll> tmp_vec(K+1);
  for(ll i = 1; i <= K; i++){
    tmp_vec[i] = i;
  
    for(ll j = 1; j*j <= i; j++){
      if(i%j == 0){
        tmp_vec[i] -= tmp_vec[j];
        if(j*j < i && j != 1){
          tmp_vec[i] -= tmp_vec[i/j];
        }
      }
    }
    tmp_vec[1] = 1;

    //cerr << i << " " << tmp_vec[i] << endl;

    ans += tmp_vec[i] * fast_power(K/i, N, MOD);
    ans = (ans + MOD)%MOD;
  }

  cerr << "Answer:" << endl;
  cout << ans << endl;

  return 0;
  
}



long long int mod(long long int x, long long int m){
  if(x>0){
    return x%m;
  }
  else if(x==0){
    return 0;
  }
  else if((-x)%m == 0){
    return 0;
  }
  else{
    return m - (-x)%m;
  }
}


long long int euclid_extended(long long int a, long long int b, long long int &x, long long int &y){
  long long int d = a;
  if(b != 0){
    d = euclid_extended(b, a%b, y, x);
    y -= (a/b)*x;
  }
  else{
    x = 1;
    y = 0;
  }
  
  return d;
}

long long int mod_inverse(long long int x, long long int m){
  long long int tmp, x_inv, gcd_xm;
  gcd_xm = euclid_extended(x, m, x_inv, tmp);
  // if the inverse is calculate properly
  if(gcd_xm == 1){
    return mod(x_inv, m);
  }
  else{
    //std::cerr << "Error in mod_inverse: there is no inverse of x in mod m" << std::endl;
    return 0;
  }
}

long long int mod_inverse_Fermat(long long int x, long long int m){
  return fast_power(x, m-2, m);
}

long long int fast_power(long long int x, long long int n, long long int m){
  long long int ans = 1;
  
  while(n > 0){
    if(n&1){
      ans = ans * x;
      ans = mod(ans, m);
    }
    x = x*x;
    x = mod(x, m);
    n = n>>1;
  }
  
  return ans;
}


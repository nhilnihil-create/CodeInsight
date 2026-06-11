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

// calculate x%m for x "properly" for all x
long long int mod(long long int x, long long int m);

// calculate inverse of x in mod m
// if there is inverse of x   : return (inverse of x)
// if there is no inverse of x: return 0
long long int mod_inverse(long long int x, long long int m);

// calculate inverse of x in mod m for PRIME m
long long int mod_inverse_Fermat(long long int x, long long int m);

// calculate x^n mod m
long long int fast_power(long long int x, long long int n, long long int m);

// extended euclid gojjohou
long long int euclid_extended(long long int a, long long int b, long long int &x, long long int &y);



long long int MOD = 998244353;

int main(){

  long long int N, tmp;
  std::vector<long long int> D;

  scanf("%lld", &N);
  for(long long int i = 0; i < N; i++){
    scanf("%lld", &tmp);
    D.push_back(tmp);
  }

  // solve problem
  std::vector<long long int> count(N);

  for(long long int i = 0; i < N; i++){
    count[D[i]]++;
  }
  /*std::cerr << "count" << std::endl;
  for(long long int i = 0; i < 10; i++){
    std::cerr << count[i] << " ";
  }std::cerr << std::endl;*/

  if(D[0] > 0 || count[0] > 1){
    std::cerr << "Answer: impossible" << std::endl;
    std::cout << 0 << std::endl;
    return 0;
  }

  long long int ans = 1;
  for(long long int i = 1; i < N; i++){
    for(long long int j = 0; j < count[i]; j++){
      ans *= count[i-1];
      ans = (ans+MOD)%MOD;
    }
    
    /*if(count[i] != 0){
      ans *= fast_power(count[i-1], count[i], MOD);
      ans = (ans+MOD)%MOD;
    }*/
  }

  std::cerr << "Answer: " << std::endl;
  std::cout << ans << std::endl;
  
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

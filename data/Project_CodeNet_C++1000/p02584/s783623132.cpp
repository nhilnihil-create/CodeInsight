#include <bits/stdc++.h>
using namespace std;



int main() {
  
  long long X, K, D;
  scanf("%lld %lld %lld", &X, &K, &D);

  if (X<0){
    X*=-1;
  }

  int direction = X>=0?-1:1;
  long long k_necessary = X/D;
  
  if (k_necessary>K){
    printf("%lld\n", X - K*D);
    return 0;
  }
  
  long long p1 = X - k_necessary*D;  
  long long p2 = p1 - D;
  long long K_left = K-k_necessary-1;

  if (K_left%2==0){
    printf("%lld\n", -p2);
  }else{
    printf("%lld\n", p1);
  }

  return 0;
}



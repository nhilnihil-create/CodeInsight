#include <iostream>
#include <vector>

// 繰り返し2乗法
int64_t modpow(int64_t a, int64_t n, int64_t mod){
  if(n == 1){
    return a % mod;
  }
  
  if(n%2 == 1){
    return (a * modpow(a, n-1, mod)) % mod;
  }
  
  int64_t t = modpow(a, n/2, mod);
  
  return (t * t) % mod;
  
}

// numberの約数を探す
std::vector<int> divisor(int number){
  std::vector<int> vec;
  for(int cnt = 1; cnt*cnt <= number; cnt++){
    if(number % cnt == 0){
      vec.push_back(cnt);
      if(cnt*cnt != number){
        vec.push_back(number/cnt);
      }
    }
  }
  return vec;
}
  


int main(){
  int N = 0;
  int K = 0;
  std::cin >> N >> K;
  
  const int64_t mod = 1000000007;
  
  std::vector<int64_t> vec_sub(K+1);
  
  int64_t answer = 0;
  for(int i = K; 0 < i; i--){
    int64_t cnt = ((modpow(K/i, N, mod)-vec_sub.at(i))%mod+mod)%mod; 
    answer = (answer+i*cnt+mod)%mod;
    
    std::vector<int> vec= divisor(i);
    for(int num : vec){
      vec_sub.at(num) = (vec_sub.at(num)+cnt+mod)%mod;
    }
    
  }
  
  std::cout << answer << std::endl;
  
  
  return 0;
}
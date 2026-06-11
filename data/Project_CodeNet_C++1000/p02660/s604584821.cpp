#include <iostream>
#include <algorithm>
#include <map>

typedef long long ll;

std::map<ll, ll> PrimeFactorization(ll num){
  std::map<ll, ll> prime_factors;
  for(ll i = 2 ; i * i <= num ; ){
    if(num % i == 0){
      num /= i;
      prime_factors[i]++;
    }else{
      i++;
    }
  }
  if(num > 1){
      prime_factors[num]++;
  }
  return prime_factors;
}

int main(){
  ll N;
  std::cin >> N;
  std::map<ll, ll> prime_factors = PrimeFactorization(N);
  ll resa = 0;
  for(auto it = prime_factors.begin() ; it != prime_factors.end() ; it++){
    ll sum = 0;
    for(ll k = 1 ; k <= it -> second + 1; k++){
      sum += k;
      if(sum > it -> second){
	resa += k - 1;
	break;
      }else{
	continue;
      }// end of if
    }// end of k
  }// end of it
  std::cout << resa << std::endl;
  return 0;
}

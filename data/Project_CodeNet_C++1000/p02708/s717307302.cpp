#include <iostream>

typedef long long ll;

int main(){
  ll N, K;
  std::cin >> N >> K;
  ll resa = 0;
  for(ll i = K ; i <= N + 1 ; i++){
    ll min = (i - 1) * i / 2;
    ll max = (N + 1) * N / 2 - (N - i) * (N - i + 1) / 2;
    resa += max - min + 1;
  }
  std::cout << resa % 1000000007<< std::endl;  
  return 0;
}
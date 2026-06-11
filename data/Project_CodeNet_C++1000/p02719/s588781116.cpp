#include <iostream>

using namespace std;

int main(){
  long long N, K;
  cin >> N >> K;
  
  N %= K;
  long long t = K - N;
  if (t < N) {
    printf("%llu\n", t);
  }else{
    printf("%llu\n", N);
  }
  
}

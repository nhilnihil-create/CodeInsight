#include <iostream>

using namespace std;

long long f(long long N){
  if (N<=1ll) {
    return 1ll;
  }else{
    return 1ll + 2ll * f(N/2ll);
  }
  
}

int main(){
  long long H;
  cin >> H;

  printf("%llu\n", f(H));
}

#include <iostream>

using namespace std;

int main(){
  unsigned long long N, A, B;
  cin >> N >> A >> B;
  unsigned long long n = N / (A + B), y = N % (A + B);
  unsigned long long b = n * A;
  if (y > A){
    b += A;
    printf("%llu\n", b);
  }else{
    b += y;
    printf("%llu\n", b);
  }
  
}

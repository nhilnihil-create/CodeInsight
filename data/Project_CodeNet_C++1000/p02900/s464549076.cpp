#include<iostream>

using namespace std;

long long gcd(long long x, long long y){
  while(y){
    long long t = x%y;
    x=y;
    y=t;
  }
  return x;
}

int main(){
  long long A, B;
  cin >> A >> B;
  int ans = 1;

  long long g = gcd(A,B);

  for (long long i = 2; i * i <= g; i++){
    if (g%i != 0) continue;
    while (g%i == 0){
      g /= i;
    }
    ans++;
  }
  if (g != 1) ans++;
  
  printf("%d\n", ans);
  
}

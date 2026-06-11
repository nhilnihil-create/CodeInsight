#include <iostream>
#include <iomanip>

using namespace std;

int gcd(int a, int b){
  int r;
  while(b != 0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {

  int n, ans = 0;
  char inp, old = '#';
  double clay, third;
  cin >> n;
  for(int a =1;a <= n;a++){
    for(int b =1;b <= n;b++){
      for(int c =1;c <= n;c++){
        ans += gcd(a, gcd(b, c));
      }
    }
  }
  cout << ans;
  return 0;
}

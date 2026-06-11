#include <cstdlib>
#include <iostream>

using namespace std;

long gcd(long x, long y){
  long t;
  if(x < y){
    long tmp = x;
    x = y;
    y = tmp;
  }
  t = x%y;
  if(t==0){
    return y;
  } else {
    return gcd(y, t);
  }
}

int main(){
  long a, b;
  cin >> a >> b;

  cout << (a*b)/gcd(a,b) << endl;
  return 0;
}

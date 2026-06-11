#include <iostream>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
  long long a,ib;
  long double b;
  cin >> a >> b;
  
  ib = (b*100)+0.5;
  a *= ib;
  a /= 100;
  
  cout << a << endl;
  
  return 0;
}

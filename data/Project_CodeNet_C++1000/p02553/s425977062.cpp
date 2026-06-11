#include <iostream>

using namespace std;

int max(int x, int y){
  if(x >= y) return x;
  else return y;
}

int main(){
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long p, q, r;
  p = max(a*c, a*d);
  q = max(b*c, b*d);
  r = max(p, q);
  cout << r << endl;
  return 0;
}
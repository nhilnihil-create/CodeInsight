#include <iostream>
#include <math.h>

int main(){
  int n, d, c;
  long x, y;
  double a;
  std::cin >> n >> d;
  c = 0;
  for(int i=0; i<n; i++){
    std::cin >> x >> y;
    a = sqrt(x*x+y*y);
    if(a <= (double)d) c++;
  }
  std::cout << c << std::endl;
}

#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
  double r,PI=3.141592653589;
  cin >> r;

  std::cout << std::fixed << std::setprecision(5) << r*r*PI << " " << 2*r*PI;;
  cout << endl;
}

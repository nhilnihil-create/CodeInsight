#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main (int argc, char **argv) {
  double r;;
  cin >> r;

  double area = M_PI * r * r;
  double len = 2 * M_PI * r;
  
  cout << fixed << setprecision(8) << area << " " << len << endl;
}
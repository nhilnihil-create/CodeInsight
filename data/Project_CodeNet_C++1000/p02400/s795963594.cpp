#include <iostream>
using namespace std;

int main() {

  double r, pi = 3.141592653589;

  cin >> r;
  double area = r * r * pi;
  double circle = 2 * r * pi;
  cout << fixed << area << " " << circle;
  
}
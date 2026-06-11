#include <iostream>
#include <iomanip>
using namespace std;

int main(){

 double r, are, circ;

 cin >> r;

 are = r * r * 3.141592653589;
 circ = r * 2 * 3.141592653589;

 cout << fixed << are << " " << circ << "\n";

 return 0;
}
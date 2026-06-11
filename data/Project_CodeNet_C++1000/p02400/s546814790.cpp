#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

int main(void) {
double r;
cin >> r;
double pi = 3.141592653589793;

cout << std::setprecision(20);
cout << pi * r * r  << " " <<  2 * pi * r << endl; 

return 0;
}
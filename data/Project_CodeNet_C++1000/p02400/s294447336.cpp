#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;
 
int main(){

double r;

cin >> r;

cout << setprecision(15) << r*M_PI*r << " " << 2*r*M_PI << endl;


return 0;
}
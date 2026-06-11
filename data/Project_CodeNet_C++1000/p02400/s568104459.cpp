#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>


using namespace std;

int main() {
    
    double r;
    cin >> r;
    cout << fixed << setprecision(20);
    cout << r * r * M_PI << " " << 2 * r * M_PI << endl;

}


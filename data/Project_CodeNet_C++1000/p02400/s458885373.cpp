#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(void){
    
    double r = 0;
    
    cin >> r;

    double menseki = r * r * M_PI;
    double ensyu = r * 2 * M_PI;
    
    cout << fixed << setprecision(6) << menseki << ' ' << ensyu << endl;
    
    return 0;   
}
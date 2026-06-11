#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void) {
        double r;
        double round, surface;
        
        cin >> r;
        round = 2 * M_PI * r;
        surface = M_PI * pow(r,2);

        cout << fixed << setprecision(5) << surface << " " << round << endl;
        
        
        return 0;
}
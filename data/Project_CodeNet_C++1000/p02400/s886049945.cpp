#include <cstdio>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){
    double r,ans1,ans2;
        
    cin >> r;
        
    ans1 = r*r*M_PI;
    ans2 = 2*r*M_PI;
    
    cout << fixed << setprecision(6) << ans1 << " " << ans2 << endl;
    
    return 0;
}
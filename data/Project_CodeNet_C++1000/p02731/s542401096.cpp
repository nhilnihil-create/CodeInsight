#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void){
    long double L,ans;
    cin >> L;
    ans = pow(L/3.0,3.0);
    cout << fixed << setprecision(8) << ans << endl;
    
}

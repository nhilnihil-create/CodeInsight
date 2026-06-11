#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int a = 0;
    int b = 0;
    int d = 0;
    int r = 0;
    double f = 0;
    
    cin >> a >> b;
    
    d = a / b;
    r = a % b;
    f = (double)a / (double)b;
    
    cout << d << " " << r << " " << fixed << setprecision(5) << f << endl;
    
    return 0;
}
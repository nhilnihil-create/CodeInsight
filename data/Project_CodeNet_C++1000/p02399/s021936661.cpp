#include <iostream>
#include <iomanip>
using namespace std;

int main(void){
    int a, b;
    cin >> a >> b;
    
    
    cout << fixed << setprecision(5) << a / b << " " << a % b << " " << static_cast<double>(a) / static_cast<double>(b) << endl;
    
    return 0;
}
#include <iostream>
#include <iomanip>

int main(){
    using namespace std;
  
    int a = 0;
    int b = 0;
    cin >> a >> b;

    int   d = a / b;
    int   r = a % b;
    double f = static_cast<double>(a) / static_cast<double>(b);

    cout << d << " " << r << " " << fixed << setprecision(5) << f << endl;

    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double a, b;
    long num1, num2;
    cin >> num1 >> num2;
    a = num1;
    b = num2;
    double x = a / b;
    cout << num1 / num2 << " " << num1 % num2  << " " << fixed << setprecision(5) << x << endl;
}
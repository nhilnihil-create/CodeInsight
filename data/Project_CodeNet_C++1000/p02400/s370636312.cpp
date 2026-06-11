#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double num;
    cin >> num;
    double test1 = (num * num) * 3.14159265359;
    double test2 = (num + num) * 3.14159265359;
    cout << fixed << setprecision(6) << test1 << " " << test2 << endl;
}
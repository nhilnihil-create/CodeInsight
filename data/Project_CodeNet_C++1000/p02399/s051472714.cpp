#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;

    cout << fixed << setprecision(6);

    cout << a / b << " ";
    cout << a % b << " ";
    cout << (double) a / b << endl;
}
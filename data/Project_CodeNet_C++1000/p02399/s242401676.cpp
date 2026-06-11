#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main(void){
    int a,b;
    double c;
    cin >> a >> b;
    c = 1.00000 * a/b;
    cout << a/b << " " << a%b << " " << fixed << setprecision(8) << c << endl;
    return 0;
}
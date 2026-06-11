#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main() {
    int a,b;
    int d,r;
    double f;
 
    cin >> a >> b;
 
    d = a / b;
    r = a % b;
    f = (double)a / (double)b;
 
    cout << d << " " << r << " " << flush;
    printf("%7f\n", f);
    return 0;
}
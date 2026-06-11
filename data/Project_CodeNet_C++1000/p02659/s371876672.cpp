#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define begin begin()
#define end end()

void _main(){
    long long a; 
    long double b; cin >> a >> b;
    int b2 = round(b*100);
    long long c = a*b2/100;
    cout << c << endl;
    return;
}
int main() {
    _main();
    return 0;
}
    
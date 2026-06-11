#include <math.h>

#include <cmath>
#include <iostream>
using namespace std;
int main() {
    string k, l;
    int s;
    cin >> s >> k;
    l = k.substr(0, s);
    if (k == l) {
        cout << k << endl;
    } else {
        cout << l << "..." << endl;
    }
    return 0;
}
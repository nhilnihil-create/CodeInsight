#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;
using Int = int64_t;
static const Int e9 = (Int)1e9;
int main() {
    Int S;
    cin >> S;
    Int x = (e9 - S % e9) % e9;
    Int y = (S + x) / e9;
    cout << "0 0 1000000000 1 " << x << " " << y << endl;
}

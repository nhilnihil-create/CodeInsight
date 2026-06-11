#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

UInt GreatestCommonDivisor(UInt a, UInt b) {
    if (b == 0) {
        return a;
    } else {
        if (a < b) {
            std::swap(a, b);
        }
        return GreatestCommonDivisor(b, a % b);
    }
}
UInt LeastCommonMultiple(UInt a, UInt b) {
    Int gcd = GreatestCommonDivisor(a, b);
    return a / gcd * b;
}
#define GCD GreatestCommonDivisor
#define LCM LeastCommonMultiple

int main(void) {
    Int a, b, c, d, e;
    cin >> a >> b >> c >> d;
    a--;
    e = LCM(c, d);

    Int s = b - b / c - b / d + b / e;
    Int t = a - a / c - a / d + a / e;
    cout << s - t << endl;
    return 0;
}

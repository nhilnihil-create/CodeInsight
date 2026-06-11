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
UInt GreatestCommonDivisor(UInt a, UInt b, UInt c) {
    return GreatestCommonDivisor(GreatestCommonDivisor(a, b), c);
}
#define GCD GreatestCommonDivisor

int main(void) {
    Int k;
    cin >> k;
    Int sum = 0;
    for (Int a = 1; a <= k; ++a) {
        for (Int b = 1; b <= k; ++b) {
            for (Int c = 1; c <= k; ++c) {
                sum += GCD(a, b, c);
            }
        }
    }
    cout << sum << endl;
    return 0;
}

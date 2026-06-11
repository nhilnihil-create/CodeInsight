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

namespace BasicMath {
    // 最大公約数を求める(ユークリッドの互除法) 
    // O(log max(a, b)) time, O(1) space
    static UInt GreatestCommonDivisor(UInt a, UInt b);
    // 最小公倍数を求める 
    // O(log max(a, b)) time, O(1) space
    static UInt LeastCommonMultiple(UInt a, UInt b);

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
}
using namespace BasicMath;

int main(void) {
    Int a, b;
    cin >> a >> b;
    cout << LCM(a, b) << endl;
    return 0;
}

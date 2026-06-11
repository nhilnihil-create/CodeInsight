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

int main(void) {
    Int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << 0.5 << endl;
    } else {
        Int half = n / 2;
        double answer = (double)(half + 1) / (double)n;
        cout << answer << endl;
    }
}

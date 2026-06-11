#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

long long int gcd(long long int a, long long int b) {
    while (a % b != 0 && b % a != 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return min(a, b);
}

long long int f(long long int a, long long int b, long long int c) {
    return a - a / b - a / c + a / (b * c / gcd(b, c));
}

int main() {
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long int res = f(b, c, d) - f(a - 1, c, d);
    cout << res << endl;
}

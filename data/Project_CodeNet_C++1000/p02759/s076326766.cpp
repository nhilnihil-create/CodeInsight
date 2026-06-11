#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n / 2 + n % 2 << endl;
    return 0;
}

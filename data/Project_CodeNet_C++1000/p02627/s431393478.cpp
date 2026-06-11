#include <math.h>

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
    char a;
    cin >> a;
    if ((int)a < (int)'a') {
        cout << 'A';
    } else {
        cout << 'a';
    }
    return 0;
}

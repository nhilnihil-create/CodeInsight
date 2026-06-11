#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using ll = long long;
using namespace std;

int main() {
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int hdiff = h2 - h1;
    int mdiff = m2 - m1;
    int htom  = hdiff * 60;
    htom += mdiff;

    cout << htom - k << endl;

    return 0;
}

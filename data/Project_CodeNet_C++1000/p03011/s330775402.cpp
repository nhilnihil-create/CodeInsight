#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    int p, q, r;
    cin >> p >> q >> r;

    int ans = 1000;

    ans = min(ans, p + q);
    ans = min(ans, q + r);
    ans = min(ans, r + p);

    cout << ans << endl;
}
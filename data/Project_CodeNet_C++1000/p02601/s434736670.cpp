#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
    int a, b, c; cin >> a >> b >> c;
    int k; cin >> k;
    while (a >= b) {
        b *= 2;
        k--;
    }
    while (b >= c) {
        c *= 2;
        k--;
    }
    if (0 <= k) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
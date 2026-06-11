
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define debug(x) (cout << # x ": " << x << endl)
#define int long long int
#define repeat(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()

signed main() {
    int a, b;
    cin >> a >> b;

    repeat(i, 2000) {
        if (i * 8 / 100 == a && i / 10 == b) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
    return 0;
}


#include <algorithm>
#include <cassert>
#include <cmath>
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
    int n, k;
    cin >> n >> k;

    int ca = n - (n / k - 1) * k;
    int cb = n - (n / k) * k;
    int cc = k - cb;
    cout << min({ca, cb, cc});
    
    return 0;
}

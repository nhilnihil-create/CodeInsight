
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
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
#define repeat(n) for (int i = 0; i < n; ++i)
#define repeat2(n) for (int j = 0; j < n; ++j)
#define all(x) (x).begin(), (x).end()

#define PRIME (1'000'000'007)
#define MAX_SIZE (100001)

signed main() {
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int i = k; i <= n + 1; ++i) {
        int min = (i + 1) * i / 2;
        int max = (2 * n - i + 3) * i / 2;
        ans = (ans + max - min + 1) % PRIME;
    }

    cout << ans;
    
    return 0;
}
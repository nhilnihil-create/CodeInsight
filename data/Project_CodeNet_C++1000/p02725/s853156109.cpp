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
    int k, n;
    cin >> k >> n;


    int a;
    cin >> a;
    int mx = 0;
    int cur = a;
    int first = a;
    repeat(i, n - 1) {
        cin >> a;
        mx = max(mx, a - cur);
        cur = a;
    }

    mx = max(mx, k - cur + first);

    cout << k - mx;
    
    return 0;
}

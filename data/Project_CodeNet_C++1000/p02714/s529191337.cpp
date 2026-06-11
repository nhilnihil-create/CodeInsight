
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
    int n;
    string s;
    cin >> n >> s;

    int nc = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int k = 2 * j - i;
            if (k >= n) break;

            if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) ++nc;
        }
    }

    auto ca = count(all(s), 'R');
    auto cb = count(all(s), 'G');
    auto cc = count(all(s), 'B');
    
    cout << ca * cb * cc - nc;
    
    return 0;
}
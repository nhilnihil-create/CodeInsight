
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
    int k;
    cin >> k;

    queue<int> q;

    repeat(i, 9) {
        q.push(i + 1);
    }

    int n;
    for (int c = 0; c < k; ++c) {
        n = q.front();
        q.pop();

        int l = n % 10;
        if (l > 0) {
            q.push(n * 10 + l - 1);
        }
        q.push(n * 10 + l);
        if (l < 9) {
            q.push(n * 10 + l + 1);
        }
    }

    cout << n;
    
    return 0;
}
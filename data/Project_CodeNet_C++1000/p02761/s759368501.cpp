#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
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
    int n, m;
    cin >> n >> m;

    vector<int> vs, vc;
    repeat(i, m) {
        int s, c;
        cin >> s >> c;
        vs.push_back(s);
        vc.push_back(c);
    }

    repeat(i, 1000) {
        auto s = to_string(i);
        if (s.size() < n) continue;

        bool flg = true;
        repeat(j, m) {
            if (s[vs[j] - 1] != '0' + vc[j]) flg = false;
        }

        if (flg) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
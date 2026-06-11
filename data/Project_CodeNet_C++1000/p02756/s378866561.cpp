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
    string s;
    int q;
    cin >> s >> q;

    deque<char> deq;
    for (auto c: s) deq.push_back(c);

    bool is_reversed = false;

    repeat(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            is_reversed = !is_reversed;
        } else if (t == 2) {
            int f; char c;
            cin >> f >> c;

            if ((f == 1) ^ is_reversed) {
                deq.push_front(c);
            } else {
                deq.push_back(c);
            }
        }
    }

    if (is_reversed) reverse(all(deq));
    for (auto c: deq) cout << c;

    return 0;
}
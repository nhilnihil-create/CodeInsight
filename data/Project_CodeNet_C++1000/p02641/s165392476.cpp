#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cassert>
#include <unordered_map>

using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, n; cin >> x >> n;
    set<int> st;
    for (int i = 0, a; i < n; ++i) {
        cin >> a;
        st.insert(a);
    }

    if (!st.count(x)) {
        cout << x << '\n';
        return 0;
    }
    int ax1 = x, ax2 = x;
    while(ax1 >= 1 && st.count(ax1)) {
        ax1--;
    }
    while(ax2 <= 100 && st.count(ax2)) {
        ax2++;
    }

    if (abs(x - ax1) == abs(x- ax2)) {
        cout << min(ax1, ax2) << '\n';
    } else if (abs(x - ax1) < abs(x - ax2)) {
        cout << ax1 << '\n';
    } else {
        cout << ax2 << '\n';
    }
    return 0;

}


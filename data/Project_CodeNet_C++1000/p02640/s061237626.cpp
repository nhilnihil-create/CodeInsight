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
    int x, y; cin >> x >> y;
    if (y & 1 || x * 4 < y || x * 2 > y) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    return 0;
}


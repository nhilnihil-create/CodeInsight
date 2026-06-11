#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main()
{
    string S, T;
    cin >> S >> T;

    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        if (S[i] == T[i]) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}

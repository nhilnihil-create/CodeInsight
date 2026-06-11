#include <iostream>
#include <cassert>
#include <limits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <array>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cstring>
#include <bitset>
#include <stack>
#include <queue>

#define MOD (1e9 + 7);
#define PI (3.14159265358979323846)

using ll = int64_t;
using ull = uint64_t;

using namespace std;

[[maybe_unused]] static auto __x = [](){ios_base::sync_with_stdio(0); cin.tie(0);};

int main() {
    string s;
    cin >> s;
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            cout << "Bad";
            return 0;
        }
    }
    cout << "Good";
}

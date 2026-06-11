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
    string T;
    cin >> T;

    for (int i = 0; i < T.size(); ++i) {
        if (T[i] == '?') {
            T[i] = 'D';
        }
    }

    cout << T << endl;

    return 0;
}

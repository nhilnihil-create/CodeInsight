#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;



int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> x;

    int L = 100, R = 105;
    int mn = (x + R - 1) / R;
    int mx = x / L;

    bool res = false;
    for (int n = mn; n <= mx; ++n) {
        int rem = x - n * L;
        if (rem >= 0 && rem <= 5 * n) {
            res = true;
        }
    }

    if (res) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }

    return 0;
}
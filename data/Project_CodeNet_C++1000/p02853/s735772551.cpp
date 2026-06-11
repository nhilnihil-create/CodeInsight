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

    int x, y;
    cin >> x >> y;

    int res = max(0, 3 + 1 - x) + max(0, 3 + 1 - y);
    if (x == 1 && y == 1) {
        res += 4;
    }
    res *= 100000;
    cout << res << '\n';
    
    return 0;
}
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
    cout << fixed << setprecision(12);


    int h1, m1, h2, m2, K;
    cin >> h1 >> m1 >> h2 >> m2 >> K;

    auto count = [&](int h, int m) {
        return h * 60 + m;
    };

    int L = count(h1, m1);
    int R = count(h2, m2);

    R -= K + 1;
    int res = max(0, R - L + 1);

    cout << res << '\n';

    return 0;
}
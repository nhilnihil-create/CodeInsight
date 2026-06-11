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

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long res = a * c;
    for (auto x : {a, b}) {
        for (auto y : {c, d}) {
            res = max(res, x * y);
        }
    }

    cout << res << '\n';

    return 0;
}
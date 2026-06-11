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

    int n;
    cin >> n;
    vector<pair<int,int>> P;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        P.emplace_back(x, y);
    }

    long long res = 0;
    const long long INF = 1LL << 40;
    vector<long long> maxs(4, -INF);
    vector<long long> mins(4, INF);
    for (int i = 0; i < n; ++i) {
        int x = P[i].first, y = P[i].second;
        for (int j = 0; j < 4; ++j) {
            long long val = 0;
            if (j & 1) {
                val += x;
            } else {
                val -= 1;
            }
            if (j & 2) {
                val += y;
            } else {
                val -= y;
            }
            maxs[j] = max(maxs[j], val);
            mins[j] = min(mins[j], val);
        }
    }
    for (int i = 0; i < 4; ++i) {
        res = max(res, maxs[i] - mins[i]);
    }
    cout << res << '\n';

    return 0;
}
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

const long long INF = 1LL << 50;

class FenwickTreeMax {
    public:
        FenwickTreeMax(int n) : N(n), data(n, -INF) {

        }

        void put(int x, long long v) {
            for (; x < N; x |= x + 1) {
                data[x] = max(data[x], v);
            }
        }

        long long get(int x) {
            long long res = -INF;
            for (; x >= 0; x = (x & (x + 1)) - 1) {
                res = max(res, data[x]);
            }
            return res;
        }

    private:
        int N;
        vector<long long> data;
};


class FenwickTreeMin {
    public:
        FenwickTreeMin(int n) : N(n), data(n, INF) {

        }

        void put(int x, long long v) {
            for (; x < N; x |= x + 1) {
                data[x] = min(data[x], v);
            }
        }

        long long get(int x) {
            long long res = INF;
            for (; x >= 0; x = (x & (x + 1)) - 1) {
                res = min(res, data[x]);
            }
            return res;
        }

    private:
        int N;
        vector<long long> data;
};


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

    sort(P.begin(), P.end());

    vector<int> Y;
    for (int i = 0; i < n; ++i) {
        Y.push_back(P[i].second);
    }
    sort(Y.begin(), Y.end());
    Y.resize(unique(Y.begin(), Y.end()) - Y.begin());

    auto index = [&](int y) {
        auto it = lower_bound(Y.begin(), Y.end(), y);
        int res = it - Y.begin();
        return res;
    };

    FenwickTreeMax ftup(n);
    FenwickTreeMax ftdown(n);

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int x = P[i].first;
        int y = P[i].second;

        int idx = index(y);
        {
            auto ans = ftdown.get(idx);
            if (ans > -INF && ans < INF) {
                ans = x + y + ans;
                res = max(res, ans);
            }
            ftdown.put(idx, -y - x);
        }
        {
            auto ans = ftup.get(n - 1 - idx);
            if (ans > -INF && ans < INF) {
                ans = ans + x - y;
                res = max(res, ans);
            }
            ftup.put(n - 1 - idx, y - x); 
        }
    }

    cout << res << '\n';


    return 0;
}
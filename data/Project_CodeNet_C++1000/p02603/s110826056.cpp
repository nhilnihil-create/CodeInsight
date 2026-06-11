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
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    long long mn = 1000;
    long long res = mn;

    vector<int> B;
    for (int i = 0; i < n; ++i) {
        if (B.empty() || B.back() != A[i]) {
            B.push_back(A[i]);
        }
    }

    n = B.size();
    long long x = mn;
    long long s = 0;
    for (int i = 0; i < n; ++i) {
        if ((i - 1 < 0 || B[i - 1] > B[i]) && (i + 1 >= n || B[i + 1] > B[i])) {
            auto cnt = x / B[i];
            x -= cnt * B[i];
            s += cnt;
        }
        if ((i - 1 < 0 || B[i - 1] < B[i]) && (i + 1 >= n || B[i + 1] < B[i])) {
            x += s * B[i];
            s = 0;
        }
        res = max(res, x);
    }

    cout << res << '\n';

    return 0;
}
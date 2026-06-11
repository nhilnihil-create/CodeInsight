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

    int n;
    cin >> n;
    vector<long long> A(n);
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (auto x : A) {
        total += x;
    }

    long long presum = 0;
    long long res = total;
    for (int i = 0; i < n - 1; ++i) {
        presum += A[i];
        res = min(res, abs(presum * 2 - total));
    }
    cout << res << '\n';
    
    return 0;
}
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

    int m;
    cin >> m;
    vector<int> D(m);
    vector<long long> C(m);
    for (int i = 0; i < m; ++i) {
        cin >> D[i] >> C[i];
    }


    long long res = 0;
    long long sum = 0;
    for (auto x : C) {
        res += x;
    }
    --res;
    for (int i = 0; i < m; ++i) {
        sum += D[i] * C[i];
    }
    res += (sum - 9 + 8) / 9;
    
    cout << res << '\n';

    return 0;
}
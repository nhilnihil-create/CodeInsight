#include <iostream>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#define int long long
using namespace std;
using Graph = vector<vector<int>>;
 
vector<bool> seen;
void dfs(const Graph& G, int v) {
    seen[v] = true; // v を訪問済にする
 
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}
signed main() {
    int L, R; cin >> L >> R;
    int M = 2019;
    bool J = false;
    if (L / 2019 == R / 2019 && L % 2019 != 0) {
        for (int X = L % 2019; X < R % 2019; X++) {
            for (int Y = L % 2019 + 1; Y <= R % 2019; Y++) {
                if ((X * Y) % 2019 < M) {
                    M = (X * Y) % 2019;
                    J = true;
                }
            }
        }
        if (J == true) {
            cout << M << endl;
        }
    }
    else {
        cout << 0 << endl;
        J=true;
    }
    if (L + 1 == R && J == false) {
        cout << ((L % 2019) * (R % 2019))%2019 << endl;
    }
}

/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>

#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>

#include <cmath>
#include <numeric>
#include <random>
#include <cstring>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <stack>

// type
#include <cstdint>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const double PI = 3.141592653589793238462643383279;
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

signed main() {
    int K, Q;
    cin >> K >> Q;
    vector<int> D(K);
    for (int i = 0; i < K; i++) cin >> D[i];
    for (int q = 0; q < Q; q++) {
        int N, X, M;
        cin >> N >> X >> M;
        vector<int> E(K);
        int e = 0;
        for (int i = 0; i < K; i++) {
            E[i] = D[i] % M;
            if (E[i] == 0) E[i] = M;
            e += E[i];
        }
        int sum = X % M;
        sum += ((N-1) / K) * e;
        for (int i = 0; i < ((N-1) % K); i++) sum += E[i];
        cout << (N-1) - sum / M << endl;
    }
}
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

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */
signed main() {
    int N;
    cin >> N;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        m[a]++;
    }
    vector<int> A;
    for (auto it = m.begin(); it != m.end(); ++it) A.push_back(it->second);
    sort(A.begin(), A.end());
    int M = A.size();

    vector<int> S(M + 1, 0);
    for (int i = 0; i < M; ++i) {
        S[i+1] = S[i] + A[i];
    }

    for (int k = 1; k <= N; ++k) {
        int lb = 0;
        int ub = N + 1;

        while (ub - lb > 1) {
            int mid = (ub + lb) / 2;

            auto it = lower_bound(A.begin(), A.end(), mid);
            int i = it - A.begin();
            int sum = (M - i) * mid + S[i];
            if (sum >= k * mid) {
                lb = mid;
            } else {
                ub = mid;
            }
        }

        cout << lb << endl;
    }

    return 0;
}
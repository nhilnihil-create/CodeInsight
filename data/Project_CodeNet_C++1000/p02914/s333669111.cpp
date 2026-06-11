#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
// constexpr ll MOD = 998244353;
constexpr ll MOD = 1000000007;

// struct UnionFind {
//     vector<int> par;
    
//     UnionFind(int N): par(N) {
//         for (int i=0;i<N;i++) par[i] = i;
//     }

//     int root(int x) {
//         if (par[x] == x) return x;
//         else return par[x] = root(par[x]);
//     }

//     void unite(int x, int y) {
//         int rx = root(x);
//         int ry = root(y);
//         if (rx == ry) return;
//         par[rx] = ry;
//     }

//     bool same(int x, int y) {
//         int rx = root(x);
//         int ry = root(y);
//         return rx == ry;
//     }
// };

int main(void) {
    int N;
    vector<ull> A(100010,0ULL);
    cin >> N;
    for (int i=0;i<N;i++) cin >> A[i];

    // 興味深くないビットを無視
    ull all = 0ULL;
    for (int i=0;i<N;i++) all ^= A[i];
    for (int i=0;i<N;i++) A[i] &= ~all;
    // 行標準形を求める
    ull rank = 0;
    for (int i=59;i>=0;i--) {
        int j;
        for (j=rank;j<N;j++) if (A[j] & (1LL << i)) break;
        if (j == N) continue; // ビットが立っていない
        if (j > rank) A[rank] ^= A[j]; // 下でビットが立っているので上に移す
        for (j = rank+1;j<N;j++) A[j] = min(A[j],A[j] ^ A[rank]);
        rank++;
    }
    ull ans = 0;
    for (int i=0;i<N;i++) ans = max(ans,ans ^ A[i]);
    cout << (ans << 1) + all << endl;

    return 0;
}

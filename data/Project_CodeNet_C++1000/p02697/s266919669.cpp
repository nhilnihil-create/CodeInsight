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
// constexpr ll MOD = 998244353;
constexpr ll MOD = 1000000007;

// struct UnionFind {
//     vector<ll> par;
//     vector<ll> siz;
    
//     UnionFind(ll N): par(N), siz(N,1) {
//         for (ll i=0;i<N;i++) par[i] = i;
//     }

//     ll root(ll x) {
//         if (par[x] == x) return x;
//         else return par[x] = root(par[x]);
//     }

//     void unite(ll x, ll y) {
//         ll rx = root(x);
//         ll ry = root(y);
//         if (rx == ry) return;
//         // if (siz[rx] < siz[ry]) swap(rx,ry);
//         par[rx] = ry;
//         siz[ry] += siz[rx];
//     }

//     bool same(ll x, ll y) {
//         ll rx = root(x);
//         ll ry = root(y);
//         return rx == ry;
//     }

//     ll size(ll x) {
//         return siz[root(x)];
//     }
// };

//     vector<ll> par;
//     vector<ll> siz;
    
//     UnionFind(ll N): par(N), siz(N,1LL) {
//         for (ll i=0;i<N;i++) par[i] = i;
//     }

//     ll root(ll x) {
//         if (par[x] == x) return x;
//         else return par[x] = root(par[x]);
//     }

//     void unite(ll x, ll y) {
//         ll rx = root(x);
//         ll ry = root(y);
//         if (rx == ry) return;
//         par[rx] = ry;
//         siz[ry] += siz[rx];
//     }

//     bool same(ll x, ll y) {
//         ll rx = root(x);
//         ll ry = root(y);
//         return rx == ry;
//     }

//     ll size(ll x) {
//         return siz[root(x)];
//     }
// };

int main(void) {
    int N, M;
    cin >> N >> M;

    if (N%2) {
        for (int i=1;i<=M;i++) cout << i << " " << N-i << endl;
    } else if (M == 1) {
        cout << 1 << " " << N << endl;
    } else {
        for (int i=1;i<=M/2;i++) cout << i << " " << N-i+1 << endl;  // << "; " << min(2*i-1,N-2*i+1) << endl;
        for (int i=M/2+2;i<=M;i++) cout << i << " " << N-i << endl; // << "; " << min(2*i,N-2*i) << endl;
        if (M%2) cout << M/2+1 << " " << N+M/2+1-M << endl;
        else cout << M/2+1 << " " << M/2+1+M << endl;
    }

    return 0;
}

#include<atcoder/all>
#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int n, q, u, v;
int main() {
    std::cin >> n >> q;
    atcoder::dsu d(n);
    rep(i, q) {
        std::cin >> n >> u >> v;
        if(n)
            std::cout << d.same(u, v) << std::endl;
        else
            d.merge(u, v);
    }
    return 0;
}
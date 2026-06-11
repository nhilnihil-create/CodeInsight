#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using usize = ::std::size_t;
using u64 = ::std::int_least64_t;
//using u64 = long long;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;


int main(int argc, char *argv[])
{
    
    
    cin.tie(0) ;
    ios::sync_with_stdio(false) ;
    
    int N, Q;
    cin >> N >> Q;
    
    dsu d(N);
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (!t) {
            d.merge(u, v);
        } else {
            cout << (d.same(u, v) ? 1 : 0) << endl;
        }
    }
    
    
    return 0;
    
}

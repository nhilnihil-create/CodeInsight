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
    fenwick_tree<u64> fw(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        fw.add(i, (u64) a);
    }
    
    while (Q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if(type) cout << fw.sum(l, r) << endl;
        else fw.add(l, (u64) r);
    }
    
    return 0;
    
}

#include <bits/stdc++.h>
//#include <atcoder/all>

using namespace std;
//using namespace atcoder;
using usize = ::std::size_t;
using u64 = ::std::int_least64_t;
//using u64 = long long;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;

u64 gcd(u64 a, u64 b) { return a ? gcd(b % a, a) : b; }


int main(int argc, char *argv[])
{
    
    cin.tie(0) ;
    ios::sync_with_stdio(false) ;
    
    int N, M;
    cin >> N >> M;
    vector<u64> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    u64 lcm = (u64) a[0];
    for (int i = 1; i < N; i++) {
        lcm = (u64) lcm * a[i] / gcd((u64) a[i], lcm);
    }
    u64 base = lcm / a[0];
    for (int i = 1; i < N; i++) {
        u64 current = lcm / a[i];
        if (base % 2 != current % 2) {
            cout << 0 << endl;
            return 0;
        }
    }
    
    u64 max_value = (u64) 2*M;
    
    u64 ans;
    ans = max_value / lcm;
    ans = (ans % 2 == 0) ? (u64) ans/2 : (u64) ans/2 + 1;
    cout << ans << endl;
    
    return 0;
    
}

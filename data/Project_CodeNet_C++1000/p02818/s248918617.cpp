#include <bits/stdc++.h>
//#include <atcoder/all>

using namespace std;
//using namespace atcoder;
using usize = ::std::size_t;
using u64 = ::std::int_least64_t;
//using u64 = long long;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;




int main(int argc, char *argv[])
{
    
    cin.tie(0) ;
    ios::sync_with_stdio(false) ;
    
    u64 A, B, K;
    cin >> A >> B >> K;
    
    B = (A <= K) ? (B - K + A) : B;
    B = max(B, (u64) 0);
    A = max(A - K, (u64) 0);
    
    cout << A << " " << B << endl;
    
    return 0;
    
}

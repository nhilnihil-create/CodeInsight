#include <bits/stdc++.h>
using namespace std;
using usize = ::std::size_t;
using u64 = ::std::int_least64_t;
//using u64 = long long;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;
int main(int argc, char *argv[])
{
    
    
    cin.tie(0) ;
    ios::sync_with_stdio(false) ;
    
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end(), std::greater<int>());
    
    u64 ans = (u64) A[0];
    
    for (int i = 2; i <= n - 1; i++) {
        ans += (u64) A[i/2];
    }
    
    cout << ans << endl;
    
    
    return 0;
    
}

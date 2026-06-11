#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main(void) {
    u64 N;
    cin >> N;

    u64 ans = 0;
    for(u64 a=1; a<N; a++) {
        u64 tans = (N - 1) / a;
        ans += tans;
    }

    cout << ans << endl;
    return 0;
}
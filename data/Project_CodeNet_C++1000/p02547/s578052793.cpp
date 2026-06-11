#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main(void) {
    u64 N;
    cin >> N;

    u64 cnt = 0;
    u64 ans = false;

    for(u64 i=0; i<N; i++) {
        u64 d0, d1;
        cin >> d0 >> d1;
        
        cnt = (d0 == d1) ? cnt + 1 : 0;
        ans |= (cnt >= 3);
    }

    if(ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
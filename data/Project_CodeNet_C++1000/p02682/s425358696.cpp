#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main(void) {
    s64 A, B, C, K;
    cin >> A >> B >> C >> K;

    if(A >= K) {
        cout << K << endl;
    } else if(A + B >= K) {
        cout << A << endl;
    } else {
        cout << A - (K - A - B) << endl;
    }

    return 0;
}
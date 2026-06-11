#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main(void) {
    u64 N;
    cin >> N;

    vector<u64> A(N);
    vector<u64> B(N);

    for(u64 n=0; n<N; n++) {
        cin >> A[n] >> B[n];
    }

    sort(A.begin(), A.end(), less<u64>());
    sort(B.begin(), B.end(), greater<u64>());

    if(N % 2) {
        u64 mdn = N / 2;
        u64 mdn_l = A[mdn];
        u64 mdn_r = B[mdn];
        cout << mdn_r - mdn_l + 1 << endl; 
    } else {
        u64 mdn = N / 2 - 1;
        long double mdn_l = (long double)(A[mdn] + A[mdn+1]) / 2;
        long double mdn_r = (long double)(B[mdn] + B[mdn+1]) / 2;
        cout << (u64)((mdn_r - mdn_l + 0.5) * 2) << endl;
    }

    return 0;
}
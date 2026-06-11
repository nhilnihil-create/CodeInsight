#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main(void) {
    u64 N, M, X;
    cin >> N >> M >> X;
    
    vector<u64> C(N);
    vector<vector<u64>> A(N, vector<u64>(M));
    vector<u64> All(M);

    for(u64 i=0; i<N; i++) {
        cin >> C[i];
        for(u64 j=0; j<M; j++) {
            cin >> A[i][j];
            All[j] += A[i][j];
        }
    }

    for(u64 j=0; j<M; j++) {
        if(All[j] < X) {
            cout << -1 << endl;
            return 0;
        }
    }

    u64 ans = UINT64_MAX;
    for(u64 i=1; i<pow(2, N); i++) {
        u64 ii = i;
        u64 n = 0;
        vector<u64>  sum(M);
        u64 tans = 0;
        boost::dynamic_bitset<> overX(M);

        while(ii > 0) {
            if(ii & 1) {
                for(u64 j=0; j<M; j++) {
                    sum[j] += A[n][j];
                    overX[j] = sum[j] >= X;
                }
                tans += C[n];
            }
            n++;
            ii /= 2;
        }

        if(overX.all()) {
            ans = min(ans, tans);
        }
    }

    cout << ans << endl;
    return 0;
}
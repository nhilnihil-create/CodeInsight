#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main() {
	u64 N, K;
	cin >> N >> K;

    vector<u64> P(N);
    vector<s64> C(N);
    
    for(u64 i=0; i<N; i++) cin >> P[i], P[i]--;
    for(u64 i=0; i<N; i++) cin >> C[i];

    s64 ans = INT64_MIN;
    
    for(u64 i=0; i<N; i++) {
        u64 v = i;
        s64 csum = 0;
        u64 cnum = 0;

        do {
            csum += C[v];    
            cnum++;
            v = P[v];
        } while(v != i);

        u64 ccnt = 0;
        s64 pans = 0;

        do {
            pans += C[v];
            v = P[v];
            ccnt++;

            s64 off = (csum > 0) ? (K - ccnt) / cnum * csum : 0;
            ans = max(ans, pans + off);
        } while(v != i && ccnt < K);

    }

    cout << ans << endl;
    return 0;
}
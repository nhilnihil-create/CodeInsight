#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main(void) {
    u64 N;
    cin >> N;

    if(N < 2) { // N is 1
        cout << 0 << endl;
        return 0;
    }

    map<u64, u64> prms;
    u64 p = 2;

    while(N >= p) {
        if(N % p == 0) {
            prms[p] = prms[p] + 1;
            N /= p;
        } else {
            p++;
            if(p*p > N) { // N is prime
                prms[N] = 1;
                break;
            }
        }
    }

    u64 ans = 0;

    for(auto itr=prms.begin(); itr!=prms.end(); itr++) {
        u64 k = 1;
        u64 val = itr->second;
        while(val >= k) {
            val -= k;
            k++;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
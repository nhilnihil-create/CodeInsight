#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

template< typename T >
T mod_pow(T x, T n, const T &p) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}

int main(void) {
    int N, P;
    string S;
    cin >> N >> P >> S;
    
    int64_t ans = 0;
    if(P ==2) {
        for(int i=0; i<N; i++) {
            if((S[i]-'0') % 2 == 0) {
                ans += i+1;
            }
        }
    } else if(P == 5) {
        for(int i=0; i<N; i++) {
            if((S[i]-'0') % 5 == 0) {
                ans += i+1;
            }
        }
    } else {
        reverse(S.begin(), S.end());
        map<int,int64_t> mp;
        int t = 0;
        for(int i=0; i<N; i++) {
            t += (S[i]-'0') * mod_pow(10, i, P);
            t %= P;
            mp[t]++;
        }
        for(auto e: mp) {
            ans += e.second * (e.second-1) / 2;
        }
        ans += mp[0];
    }

    cout << ans << endl;
    return 0;
}

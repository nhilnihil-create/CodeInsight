#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

Int P;

Int modpow(Int a, Int n) {
    Int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % P;
        a = a * a % P;
        n >>= 1;
    }
    return res;
}

int main(){ 
    Int N;
    cin >> N >> P;
    string S;
    cin >> S;

    vector<int> s(N);

    rep(i,N) {
        s[i] = S.at(i) - '0';
    }

    //rep(i,S.size()) cout << s.at(i) << endl;

    Int cnt = 0;

    if (P == 2) {
        rep(i,N) {
            if (s[i] % 2 == 0) cnt += i+1;
        }
    }
    else if (P == 5) {
        rep(i,N) {
            if (s[i] % 5 == 0) cnt += i+1;
        }
    }
    else {
        Int U = 0;
        vector<Int> m(P,0);
        m[0] = 1;
        rep(i,N) {
            U = (U + s[N-1-i] * modpow(10,i)) % P;
            cnt += m[U];
            m[U]++;
        }
        
    }
    cout << cnt << endl;

}
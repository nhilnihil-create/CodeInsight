#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using std::vector;
using std::printf;
using std::cout;
using std::endl;
using std::string;
using std::cin;

#define i64t long long int

template<typename T>
void dump(vector<T> vec) {
    for (auto x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

// ---------------------------

const i64t MOD = 1000000007;

int main() {
    i64t N;
    cin >> N;

    string S; 
    cin >> S;

    // determine
    string LR(S);
    LR[0] = 'L';
    for (int i = 1; i < 2 * N; ++i) {
        if (S[i] == S[i-1]) {
            LR[i] = (LR[i-1] == 'L') ? 'R' : 'L';
        }
        else {
            LR[i] = LR[i-1];            
        }
    }

    i64t lc = 0, rc = 0;
    for (int i = 0; i < 2 * N; ++i) {
        if (LR[i] == 'L') { lc++; }
        else { rc++; }
    }

    // cout << S << endl;
    // cout << LR << endl;
    // printf("%lld %lld\n", lc, rc);
    
    i64t ret;
    if (LR[2*N-1] != 'R') {
        ret = 0;
    }
    else if (S[0] != 'B') {
        ret = 0;
    }
    else if (lc != rc) {
        ret = 0;
    }
    else {
        i64t ll = 0, tot = 1;
        for (int i = 0; i < 2 * N; ++i) {
            if (LR[i] == 'L') {
                ll++;
            }
            else {
                tot = (tot * ll) % MOD;
                ll--;
            }
            // printf("DEBUG: %d %lld %lld\n", i, ll, tot);
        }

        ret = tot;
        for (i64t i = 1; i < N+1; ++i) {
            ret = (ret * i) % MOD;
        }
    }

    printf("%d", (int)ret);
}
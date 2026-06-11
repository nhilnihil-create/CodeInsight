#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const string YES = "Yes";
const string NO = "No";

void solve(long long A, long long B, long long C, long long K) {
    while (A >= B) B *= 2, K--;
    while (B >= C) C *= 2, K--;
    if( K >= 0 ){
        cout << YES << endl;
    }else{
        cout << NO << endl;
    }

}

int main() {
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    long long C;
    scanf("%lld", &C);
    long long K;
    scanf("%lld", &K);
    solve(A, B, C, K);
    return 0;
}

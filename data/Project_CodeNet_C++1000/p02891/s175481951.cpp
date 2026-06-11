#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
    string S;
    cin >> S;
    Int K, N;
    cin >> K;
    N = S.size();

    set<char> X;
    rep(i,N) X.insert(S[i]);
    if (X.size() == 1) {
        cout << (K * N) / 2 << endl;
        return 0;
    }

    vector<bool> changed(N,false);

    Int m = 0;
    if (N > 1) {
        rep(i,N-1) {
            if (S[i] == S[i+1] && !changed[i]) {
                m++;
                changed[i+1] = true;
            }
        }
    }

    Int ans = 0;
    ans = m * K;

    if (S[0] == S[N-1]) {
        Int y, z;
        rep1(i,N-1) {
            if (S[i] != S[0]) {
                y = i;
                break;
            }
        }
        for (int j = N-2; j>=0; j--) {
            if (S[j] != S[N-1]) {
                z = N-1-j;
                break;
            }
        }
        if (y % 2 == 1 && z % 2 == 1) ans += K-1;
    }

    cout << ans << endl;
}
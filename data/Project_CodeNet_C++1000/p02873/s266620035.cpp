#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;


int main(){ 
    string S;
    cin >> S;
    int N;
    N = S.size() + 1;

    vector<int> A(N,0);

    rep1(i,N-1) {
        if (S[i-1] == '<') {
            A[i] = max(A[i], A[i-1]+1);
        }
    }

    rep1(i,N-1) {
        if (S[N-1-i] == '>') {
            A[N-1-i] = max(A[N-1-i], A[N-i]+1);
        }
    }

    Int ans = 0;

    rep(i,N) ans += A[i];

    cout << ans << endl;
}

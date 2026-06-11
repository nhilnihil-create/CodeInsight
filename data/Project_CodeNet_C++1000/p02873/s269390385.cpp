#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

int A[500010];

int main() {
    string S;
    cin >> S;

    rep(i, S.size()+1) A[i] = 0;
    
    for (int i=0; i<S.size(); i++) {
        if (S[i] == '<') A[i+1] = A[i] + 1;
    }
    for (int i=S.size()-1; i>=0; i--) {
        if (S[i] == '>') A[i] = max(A[i], A[i+1]+1);
    }

    ll ans = 0;
    rep(i, S.size()+1) ans += A[i];

    cout << ans << endl;
    
    return 0;
}


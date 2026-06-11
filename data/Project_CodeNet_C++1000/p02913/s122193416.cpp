#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> Zalgorithm(string S) {
    vector<int> A(S.size());
    A[0] = S.size();
    int i = 1, j = 0;
    while (i < S.size()) {
        while (i+j < S.size() && S[j] == S[i+j]) ++j;
        A[i] = j;
        if (j == 0) { ++i; continue;}
        int k = 1;
        while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
        i += k; j -= k;
    }
    return A;
}

int main() {
    int N, ans = 0;
    string S;
    cin >> N >> S;
    rep(i, N - 1) {
        auto A = Zalgorithm(S.substr(i, N - i));
        for (int j = 1; j < N - i; j++) {
            ans= max(ans, min(A[j], j));
        }
    }
    cout << ans << "\n";
}
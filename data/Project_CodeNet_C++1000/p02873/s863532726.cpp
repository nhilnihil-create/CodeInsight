#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    string S; cin >> S;
    int N = S.size();
    vector<int> A(N+1,0);
    rep(i,N) {
        if (S[i] == '<') chmax(A[i+1], A[i] + 1);
    }
    for (int i = N; i > 0; i--) {
        if (S[i-1] == '>') chmax(A[i-1], A[i] + 1);
    }
    cout << accumulate(A.begin(), A.end(), 0LL) << endl;
}

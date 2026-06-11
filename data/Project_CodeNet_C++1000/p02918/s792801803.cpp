#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N,K; cin >> N >> K;
    string S; cin >> S;
    int j = 0;
    rep(i,K) {
        int s = 0;
        char c = S[0];
        for(; j<N; j++) if (c != S[j]) break;
        if (j == N) break;
        s = j;
        c = S[j];
        for(; j<N; j++) if (c != S[j]) break;
        c = (c == 'L') ? 'R' : 'L';
        fill(S.begin()+s, S.begin()+j, c);
    }
    int cnt = 0, sum = 0;
    rep(i,N-1) {
        if (S[i] == S[i+1]) cnt++; else cnt = 0;
        sum += (cnt > 0);
    }
    cout << sum << endl;
}

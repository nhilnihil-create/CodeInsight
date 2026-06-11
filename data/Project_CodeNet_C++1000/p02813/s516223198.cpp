#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> Q(N);
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];

    auto copy_P = P;
    auto copy_Q = Q;
    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());

    int p_i = 1;
    int q_i = 1;

    do {
        int cnt = 0;
        for(int i = 0; i < N; ++i) {
            if(P[i] == copy_P[i]) ++cnt;
        }
        ++p_i;
        if(cnt == N) break;
    } while(next_permutation(P.begin(), P.end()));

    do {
        int cnt = 0;
        for(int i = 0; i < N; ++i) {
            if(Q[i] == copy_Q[i]) ++cnt;
        }
        ++q_i;
        if(cnt == N) break;
    } while(next_permutation(Q.begin(), Q.end()));

    cout << abs(p_i - q_i) << endl;
    return 0;
}
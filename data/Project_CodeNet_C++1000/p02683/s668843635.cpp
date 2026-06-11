#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int N,M,X; cin >> N >> M >> X;
    int A[15][15] = {};
    int C[15] = {};
    ll ans = 1e9;

    for(int i=0; i<N; i++) {
        cin >> C[i];
        for(int j=0; j<M; j++) {
            cin >> A[i][j];
        }
    }

    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<N); ++bit) {
        int alg[15] = {};
        ll value = 0;
        vector<int> S;
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }

        for (int i = 0; i < (int)S.size(); ++i) {
            bool judge = true;
            value += C[S[i]];
            for(int j=0; j<M; j++) {
                alg[j] += A[S[i]][j];
                if(alg[j]<X) judge = false;
            }
            if(judge) {
                if(ans > value) ans = value;
            }
        }
    }
    if(ans == 1e9) ans = -1;
    cout << ans << endl;
}
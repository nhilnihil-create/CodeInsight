#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M,X;
    cin >> N >> M >> X;
    vector<int>C(N);
    vector<vector<int>>A(N,vector<int>(M));
    for(int i = 0; i < N; i++) {
        cin >> C[i];
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    int ans = INF;
    for(int bit = 0; bit < (1 << N); bit++) {
        int cnt = 0;
        vector<int>res(M);
        for(int i = 0; i < N; i++) {
            if(1 & (bit >> i)) {
                cnt+=C[i];
                for(int j = 0; j < M; j++) {
                    res[j]+=A[i][j];
                }
            }
        }
        bool ok = true;
        for(int i = 0; i < M; i++) {
            if(res[i] < X) {
                ok = false;
            }
        }
        if(ok) {
            ans = min(ans,cnt);
        }
    }
    if(ans == INF) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
}

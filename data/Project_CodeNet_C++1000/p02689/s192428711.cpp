#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    cin >> N >> M;
    vector<int>H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }
    vector<vector<int>>cnt(N);
    for(int i = 0; i < M; i++) {
        int A,B;
        cin >> A >> B;
        A--;B--;
        cnt[A].push_back(B);
        cnt[B].push_back(A);
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        bool ok = true;
        for(int j = 0; j < cnt[i].size(); j++) {
            if(H[cnt[i][j]] >= H[i]) {
                ok = false;
            }
        }
        if(ok) {
            ans++;
        }
    }
    cout << ans << endl;
}
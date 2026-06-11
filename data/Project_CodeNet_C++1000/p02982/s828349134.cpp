#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,D;
    cin >> N >> D;
    vector<vector<int>>X(N,vector<int>(D));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < D; j++) {
            cin >> X[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int cnt = 0;
            for(int k = 0; k < D; k++) {
                cnt+=abs(X[i][k]-X[j][k])*abs(X[i][k]-X[j][k]);
            }
            bool ok = false;
            for(int k = 0; k <= 300; k++) {
                if(k*k == cnt) {
                    ok = true;
                }
            }
            if(ok) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

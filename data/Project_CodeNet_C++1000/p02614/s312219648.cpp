#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int H,W,K;
    cin >> H >> W >> K;
    vector<string>c(H);
    for(int i = 0; i < H; i++) {
        cin >> c[i];
    }
    int ans = 0;
    for(int bit = 0; bit < (1 << (H+W)); bit++) {
        int cnt = 0;
        for(int i = 0; i < H; i++) {
            if(1 & (bit >> i)) {
                continue;
            }
            for(int j = 0; j < W; j++) {
                if(1 & (bit >> (H+j))) {
                    continue;
                }
                if(c[i][j] == '#') {
                    cnt++;
                }
            }
        }
        if(cnt == K) {
            ans++;
        }
    }
    cout << ans << endl;
}

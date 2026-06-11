#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int M,D;
    cin >> M >> D;
    int ans = 0;
    for(int i = 1; i <= M; i++) {
        for(int j = 22; j <= D; j++) {
            if(j/10 <= 1 || j%10 <= 1) {
                continue;
            }
            if((j/10)*(j%10) == i) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[1000005];
signed main() {
    int N;
    cin >> N;
    int X = N;
    for(int i = 2; i*i <= N; i++) {
        int res = 0;
        while (X%i == 0) {
            X/=i;
            res++;
        }
        cnt[i] = res;
    }
    int ans = 0;
    if(X >= 2) {
        ans++;
    }
    for(int i = 0; i <= 1000000; i++) {
        int res = 0;
        for(int j = 1; j <= cnt[i]; j++) {
            if(res+j <= cnt[i]) {
                ans++;
            }
            res += j;
        }
    }
    cout << ans << endl;
}

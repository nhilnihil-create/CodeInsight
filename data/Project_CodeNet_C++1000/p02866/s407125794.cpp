#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[100005];
signed main() {
    int N;
    cin >> N;
    vector<int>D(N);
    for(int i = 0; i < N; i++) {
        cin >> D[i];
        cnt[D[i]]++;
    }
    if(cnt[0] != 1 || D[0] != 0) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= cnt[i]; j++) {
            ans*=cnt[i-1];
            ans%=mod;
        }
    }
    cout << ans << endl;
}

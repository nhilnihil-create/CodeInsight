#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    vector<int>cnt(N+1);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        ans+=A[i];
        cnt[i+1]+=A[i];
    }
    int res = ans;
    for(int i = 0; i < N; i++) {
        cnt[i+1]+=cnt[i];
        ans = min(ans,abs(cnt[i+1]*2-res));
    }
    cout << ans << endl;
}

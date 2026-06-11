#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[1005][1005] = {0};
int D[1005] = {0};
int C[1005] = {0};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        cnt+=A[i];
    }
    int ans = cnt;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum+=A[i];
        ans = min(ans,abs(sum-(cnt-sum)));
    }
    cout << ans << endl;
}

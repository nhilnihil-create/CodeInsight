#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[3];
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    int ans = 1;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        int res = 0,now = -1;
        for(int j = 0; j < 3; j++) {
            if(A[i] == cnt[j]) {
                res++;
                now = j;
            }
        }
        if(now == -1) {
            cout << 0 << endl;
            return 0;
        }
        ans*=res;
        ans%=INF;
        cnt[now]++;
    }
    cout << ans << endl;
}

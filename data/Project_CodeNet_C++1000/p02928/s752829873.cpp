#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,K;
    cin >> N >> K;
    vector<int>A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int cnt1 = 0;
        int cnt2 = 0;
        for(int j = 0; j < N; j++) {
            if(A[i] > A[j]) {
                cnt1++;
                if(i < j) {
                    cnt2++;
                }
            }
        }
        ans+=cnt2*K%INF;
        ans+=K*(K-1)/2%INF*cnt1%INF;
        ans%=INF;
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum+=A[i];
        if(i%2) {
            cnt+=A[i]*2;
        }
    }
    vector<int>ans(N,-1);
    ans[0] = sum-cnt;
    for(int i = 1; i < N; i++) {
        ans[i] = A[i-1]*2-ans[i-1];
    }
    for(int i = 0; i < N; i++) {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

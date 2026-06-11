#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 1;
    for(int i = 0; i < N; i++) {
        if(INF/A[i] < ans) {
            cout << -1 << endl;
            return 0;
        }
        else {
            ans *= A[i];
        }
    }
    cout << ans << endl;
}

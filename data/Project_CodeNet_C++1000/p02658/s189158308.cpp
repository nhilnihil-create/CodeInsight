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
    int cnt = A[0];
    for(int i = 1; i < N; i++) {
        if(INF%A[i] == 0) {
            if(INF/A[i] < cnt) {
                cout << -1 << endl;
                return 0;
            }
            cnt *= A[i];
        }
        else {
            if(INF/A[i] <= cnt) {
                cout << -1 << endl;
                return 0;
            }
            cnt *= A[i];
        }
    }
    cout << cnt << endl;
}

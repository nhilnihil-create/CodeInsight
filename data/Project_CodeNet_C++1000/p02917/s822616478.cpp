#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1234567;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>B(N-1);
    for(int i = 0; i < N-1; i++) {
        cin >> B[i];
    }
    int ans = B[0]+B[N-2];
    for(int i = 1; i < N-1; i++) {
        ans+=min(B[i],B[i-1]);
    }
    cout << ans << endl;
}

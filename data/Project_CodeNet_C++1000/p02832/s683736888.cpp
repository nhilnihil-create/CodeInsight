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
    vector<int>a(N);
    int cnt = 1;
    int res = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(a[i] == cnt) {
            res++;
            cnt++;
        }
    }
    if(res == 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << N-res << endl;
}

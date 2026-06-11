#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int M;
    cin >> M;
    int cnt = 0;
    int cnt2 = 0;
    for(int i = 0; i < M; i++) {
        int d,c;
        cin >> d >> c;
        cnt2+=c;cnt+=d*c;
    }
    cout << cnt2-1+(cnt-1)/9 << endl;
}

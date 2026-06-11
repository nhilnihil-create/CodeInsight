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
    string S;
    cin >> N >> S;
    int ans = 0;
    for(int i = 0; i <= 999; i++) {
        string T = to_string(i);
        int N = T.size();
        for(int j = 0; j < 3-N; j++) {
            T = '0'+T;
        }
        int now = 0;
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == T[now]) {
                now++;
            }
            if(now == 3) {
                break;
            }
        }
        if(now == 3) {
            ans++;
        }
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,K,R,S,P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(i >= K) {
            if(T[i-K] == T[i]) {
                T[i] = 'z';
                continue;
            }
        }
        if(T[i] == 'r') ans+=P;
        if(T[i] == 's') ans+=R;
        if(T[i] == 'p') ans+=S;
    }
    cout << ans << endl;
}

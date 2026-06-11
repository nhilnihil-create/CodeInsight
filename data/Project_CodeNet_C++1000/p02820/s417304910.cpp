#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,K;
    int R,S,P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(T[i%K] == T[i] && i >= K) {
            T[i%K] = 'n';
        }
        else {
            if(T[i] == 'r') {
                ans+=P;
                T[i%K] = T[i];
            }
            else if(T[i] == 's') {
                ans+=R;
                T[i%K] = T[i];
            }
            else {
                ans+=S;
                T[i%K] = T[i];
            }
        }
    }
    cout << ans << endl;
}

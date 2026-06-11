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
    string S;
    cin >> N >> K >> S;
    int cnt = 0;
    int ans = 0;
    for(int i = 1; i < N; i++) {
        if(S[i] != S[i-1]) {
            cnt++;
        }
        else {
            ans++;
        }
    }
    cout << min(N-1,ans+2*min(cnt,K)) << endl;
}

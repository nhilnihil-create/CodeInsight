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
    int ans = 0;
    for(int i = 0; i < N-1; i++) {
        if(S[i] == S[i+1]) {
            ans++;
        }
    }
    cout << min(N-1,ans+2*K) << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,K;
    cin >> N >> K;
    if(K > (N-1)*(N-2)/2) {
        cout << -1 << endl;
        return 0;
    }
    int res = 0;
    cout << N-1+((N-1)*(N-2)/2-K) << endl;
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            if(res == N-1+((N-1)*(N-2)/2-K)) {
                return 0;
            }
            cout << i << " " << j << endl;
            res++;
        }
    }
}

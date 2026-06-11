#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[100005];
signed main()  {
    int N,X,Y;
    cin >> N >> X >> Y;
    vector<int>ans(N+1);
    for(int i = 1; i < N; i++) {
        for(int j = i+1; j <= N; j++) {
            ans[min(j-i,abs(X-i)+abs(Y-j)+1)]++;
        }
    }
    for(int i = 1; i < N; i++) {
        cout << ans[i] << endl;
    }
}

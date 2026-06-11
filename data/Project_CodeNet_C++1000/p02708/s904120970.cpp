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
    int N,K;
    cin >> N >> K;
    int ans = 0;
    vector<int>cnt(N+1);
    for(int i = 1; i <= N; i++) {
        cnt[i] = cnt[i-1]+i;
    }
    // 0 1 3 6
    for(int i = K; i <= N; i++) {
        ans+=(cnt[N]-cnt[N-i]-cnt[i-1]+1)%INF;
    }
    cout << (ans+1)%INF << endl;
}

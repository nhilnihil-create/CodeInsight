#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N,K;
vector<int>ki[100005];
bool used[100005];
int cnt[100005];
void dfs(int now) {
    used[now] = true;
    int res = 0;
    for(int next:ki[now]) {
        if(used[next]) {
            res++;
        }
    }
    cnt[now] += K-res;
    for(int next:ki[now]) {
        if(!used[next]) {
            cnt[next]-=res;
            dfs(next);
            res++;
        }
    }
}
signed main() {
    cin >> N >> K;
    for(int i = 0; i < N-1; i++) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        ki[a].push_back(b);
        ki[b].push_back(a);
    }
    dfs(0);
    int ans = 1;
    for(int i = 0; i < N; i++) {
        ans *= cnt[i];
        ans %= mod;
    }
    cout << ans << endl;
}

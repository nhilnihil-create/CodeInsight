#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int>cnt[200005];
void dfs(int now,vector<int> &ans,vector<bool> &flag) {
    flag[now] = true;
    for(int i = 0; i < cnt[now].size(); i++) {
        if(flag[cnt[now][i]] == false) {
            ans[cnt[now][i]]+=ans[now];
            dfs(cnt[now][i],ans,flag);
        }
    }
    return;
}
signed main()  {
    int N,Q;
    cin >> N >> Q;
    for(int i = 0; i < N-1; i++) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        cnt[a].push_back(b);
        cnt[b].push_back(a);
    }
    vector<int>ans(N);
    for(int i = 0; i < Q; i++) {
        int p,x;
        cin >> p >> x;
        p--;
        ans[p]+=x;
    }
    vector<bool>flag(N,false);
    dfs(0,ans,flag);
    for(int i = 0; i < N; i++) {
        cout << ans[i];
        if(i+1 != N) {
            cout << " ";
        }
    }
    cout << endl;
}
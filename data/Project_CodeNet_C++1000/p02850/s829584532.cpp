#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

vector<P> G[MAX_N];

int now = 0;
int ans = 0;

int col[MAX_N];

void dfs(int x){
    int keep = now;
    rep(i,G[x].size()){
        if(col[G[x][i].second] != -1){
            ;
        }else{
            col[G[x][i].second] = (now + 1) % ans;
            now++;
            dfs(G[x][i].first);
        }
    }
    now = keep;
}

int main() {
    int n;
    cin >> n;

    int cnt[n] = {};
    rep(i,n)col[i] = -1;

    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(P(b,i));
        G[b].push_back(P(a,i));
        cnt[a]++;
        cnt[b]++;
        ans = max(ans, cnt[a]);
        ans = max(ans, cnt[b]);
    }

    // dfs(0);

    queue<pair<int,int>> que;
    que.push(P(0,-1));

    while(que.size() > 0){
        int x = que.front().first;
        now = que.front().second;
        que.pop();

        

        rep(i, G[x].size()){
            if(col[G[x][i].second] == -1){
                col[G[x][i].second] = (now+1) % ans;
                now++;
                que.push(P(G[x][i].first, col[G[x][i].second]));
            }
        }

    }


    cout << ans << endl;
    rep(i,n-1)cout << col[i] + 1 << endl;

    return 0;
}



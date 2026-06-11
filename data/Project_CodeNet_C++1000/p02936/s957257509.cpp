#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

const int MAX_V = 200005;
vec v[MAX_V];
int cnt[MAX_V];

int main(){
    int n, q;
    cin >> n >> q;
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    rep(i, q){
        int p, x;
        cin >> p >> x;
        p--;
        cnt[p] += x;
    }
    int ans[n];
    fill(ans, ans + n, 0);
    queue<P> que;
    bool visited[n];
    fill(visited, visited + n, false);
    que.push(P(0, cnt[0]));
    ans[0] = cnt[0];
    visited[0] = true;
    while(que.size()){
        P p = que.front();
        que.pop();
        int e = p.first, c = p.second;
        rep(i, v[e].size()){
            if(visited[v[e][i]]) continue;
            ans[v[e][i]] = c + cnt[v[e][i]];
            que.push(P(v[e][i], c + cnt[v[e][i]]));
            visited[v[e][i]] = true;
        }
        // cout << 1 << endl;
    }


    rep(i, n) cout << ans[i] << " ";
    cout << endl;
}
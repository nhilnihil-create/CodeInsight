#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int mod = 1000000007;
int K;
ll ans;
vector<vector<int> > to(100005);

void dfs(int v, int f, int d){
    int n = 0;
    int s = to[v].size();
    int k = K-2;
    if(d == 0){
        k++;
        s++;
    }
    for (int i = 0; i < s-1; i++){
        ans *= k;
        ans %= mod;
        k--;
    }
    if(d == 0){
        s--;
    }
    for (int i = 0; i < s; i++){
        int x = to[v][i];
        if(x == f)continue;
        dfs(x, v, ++d);
    }
    return;
}

int main() {
    int N; cin >> N >> K;
    rep(i, N-1){
        int a, b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    ans = K;
    dfs(0, -1, 0);

    cout << ans << endl;

    return 0;
}
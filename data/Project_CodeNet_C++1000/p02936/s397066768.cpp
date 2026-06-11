#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, Q;
    cin >> N >> Q;
    vec<vec<int>> G(N,vec<int>());
    
    rep(i, N-1) {
        int a,b;
        cin >> a >> b;
        --a,--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    vec<ll> p(N);
    rep(i, Q) {
        int index,x;
        cin >> index >> x;
        --index;
        p[index] += x;
    }

    function<void(int,int)> dfs = [&](int now, int par){
        if(par != -1) p[now]+=p[par];
        for(auto e:G[now]){
            if(e == par) continue;
            dfs(e,now);
        }
    };
    dfs(0,-1);

    rep(i,N) {
        cout << p[i] << " ";
    }
    cout << endl;
}

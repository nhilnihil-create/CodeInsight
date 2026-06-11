#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
    }
    int s,t;
    cin >> s >> t;
    s--;t--;
    vector<vector<int>> seen(n,vector<int>(3,-1));
    int kaisu =0, l=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        queue<int> nq;
        swap(q,nq);
        while(!nq.empty()){
            int u=nq.front();
            nq.pop();
            if(seen[u][l]==-1){
                seen[u][l] = kaisu;
                for(int nu:G[u]){
                    q.push(nu);
                }
            }
        }
        kaisu++;
        l=(l+1)%3;
    }

    int ans = seen[t][0];
    ans/=3;
    if(ans==0)ans = -1;
    cout << ans <<endl;
    return 0;
}

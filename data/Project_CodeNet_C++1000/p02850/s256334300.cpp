#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
vector<int> color;
vector<vector<P> > edge;
int maxv = 0;
void solve(int now, P past){
    int c = 1;
    for (const auto &x : edge[now]){
        if (x.first==past.first) continue;
        if (c==past.second) c+=1;
        color[x.second] = c;
        maxv = max(maxv, c);
        if (edge[x.first].size()!=0) solve(x.first, P(now, c));
        c += 1;
    }
}

int main(){
    int n, a, b; sc(n);
    edge.resize(n), color.resize(n-1,0);
    rep(i, 0, n-1){
        sc(a), sc(b);
        a--, b--;
        edge[a].push_back(P(b,i));
        edge[b].push_back(P(a,i));
    }
    solve(0, P(0, 0));
    cout << maxv << endl;
    rep(i, 0, n-1) cout << color[i] << endl;
    return 0;
}
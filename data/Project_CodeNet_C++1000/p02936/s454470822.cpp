#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

vector<vector<ll>> tree(200010);
vector<ll> point(200010, 0);

void dfs(ll crr, ll parent){
    rep(i, tree[crr].size()){
        if(tree[crr][i] == parent)continue;

        point[tree[crr][i]] += point[crr];
        dfs(tree[crr][i], crr);
    }
}

int main(){
    ll n, q;
    cin >> n >> q;

    rep(i, n-1){
        ll a, b;
        cin >> a >> b;

        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    rep(i, q){
        ll p, x;
        cin >> p >> x;

        p--;
        point[p] += x;
    }

    dfs(0, 0);

    rep(i, n)cout << point[i] << " ";
}
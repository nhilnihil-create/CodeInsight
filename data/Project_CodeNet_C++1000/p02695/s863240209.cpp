#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;

typedef unordered_map<ll, unordered_map<ll, ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 1000000007;

ll n,m,q;
vector<tuple<ll,ll,ll,ll>> query;

ll calc(v1 &mem){
    ll ret = 0;
    for(ll i = 0;i < q;i++){
        ll a,b,c,d;
        tie(a, b, c, d) = query[i];
        if(mem[b]-mem[a] == c){
            ret += d;
        }
    }
    return ret;
}

ll dfs(v1 &mem, ll d){
    ll ans = 0;
    if(d > n){
        return calc(mem);
    }
    for(ll i = mem[d-1];i <= m;i++){
        mem[d] = i;
        ans = max(ans, dfs(mem, d+1));
    }
    return ans;
}

int main(){
    cin >> n >> m >> q;
    query = vector<tuple<ll,ll,ll,ll>>(q);
    for(ll i = 0;i < q;i++){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        query[i] = make_tuple(a,b,c,d);

    }
    v1 mem = v1(n+1);
    mem[0] = 1;

    cout << dfs(mem, 1) << endl;


}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll N, K;
ll ANS[100100];
vector<ll> G[100100];

void dfs(ll v, ll num, bool first){
    ANS[v] = K - num;
    ll visit = 1 + (!first);
    for(auto&& n : G[v]){
        if(ANS[n] != -1) continue;
        dfs(n, visit, false);
        visit++;
    }
}

int main(){
    cin >> N >> K;
    REP(i,N-1){
        ll a,b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    fill(ANS, ANS+N, -1);
    dfs(0, 0, true);

    ll ans = 1;
    REP(i,N){
        ans *= max(0LL, ANS[i]);
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}

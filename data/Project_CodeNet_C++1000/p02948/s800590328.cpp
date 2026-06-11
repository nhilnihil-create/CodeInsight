#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, M;
vector<ll> task[100010];
priority_queue<ll> que;

signed main(){
    cin >> N >> M;
    ll A, B;
    REP(i, N){
        cin >> A >> B;
        task[A].push_back(B);
    }
    ll ans = 0;
    REP(i, M + 1){
        for(ll a : task[i]) que.push(a);
        if(que.empty()) continue;
        ans += que.top();
        que.pop();
    }
    PRINT(ans);
}
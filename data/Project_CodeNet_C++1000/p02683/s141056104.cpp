#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define pb push_back
#define ALL(v) v.begin(),v.end()
const long long INF = 1LL << 60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;
int main()
{
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> C(N);
    vector<vector<int>> A(N);
    rep(i, N){
        cin >> C[i];
        rep(j, M){
            int a;
            cin >> a;
            A[i].pb(a);
        }
    }
    ll inf = 1e18;
    ll ans =inf;
    for(ll cond = 1 ; cond < 1<<(N+1) ; ++cond){
        vector<int> B(M, 0);
        ll cost = 0;
        rep(i, N)
        {
            if(!(cond &(1<<i))) continue;
            rep(j, M) B[j] += A[i][j];
            cost += C[i];
        }
        bool ok = true;
        rep(i, M){
            if(B[i] < X) ok = false;
        }
        if(ok){
            chmin(ans, cost);
        }
    }
    if(ans != inf) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
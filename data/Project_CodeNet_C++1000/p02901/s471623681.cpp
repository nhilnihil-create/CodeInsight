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

ll DP[1010][1<<13];

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M);
    vector<ll> C(M);
    REP(i,M){
        ll a, b;
        cin >> a >> b;
        A[i] = a;
        ll bit = 0;
        REP(j,b){
            ll c;
            cin >> c;
            c--;
            bit |= (1 << c);
        }
        C[i] = bit;
    }

    const ll INF = 1e15;
    REP(i,M+1) REP(j,1<<N) DP[i][j] = INF;
    DP[0][0] = 0;
    REP(i,M){
        ll a = A[i];
        ll c = C[i];
        REP(b, 1<<N){
            chmin(DP[i+1][b | c], DP[i][b] + a);
            chmin(DP[i+1][b], DP[i][b]);
        }
    }

    ll ans = -1;
    ans = DP[M][(1 << N) - 1];

    if(ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}

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

typedef pair<ll, ll> P;

ll DP[7100][7100][2];

int main(){
    ll N, T;
    cin >> N >> T;
    vector<P> AB(N);
    REP(i,N){
        ll a, b;
        cin >> a >> b;
        AB[i] = P(b, a);
    }

    //sort(AB.begin(), AB.end());

    REP(i,3100){
        REP(j,3100) {
            DP[i][j][0] = DP[i][j][1] = -1e16;
        }
    }
    DP[0][0][0] = 0;

    REP(i,N){
        auto p = AB[i];
        ll a = p.second;
        ll b = p.first;
        REP(j,3010){
            chmax(DP[i+1][j][0], DP[i][j][0]);
            chmax(DP[i+1][j+a][0], DP[i][j][0] + b);
            chmax(DP[i+1][j][1], DP[i][j][0] + b);

            chmax(DP[i+1][j][1], DP[i][j][1]);
            chmax(DP[i+1][j+a][1], DP[i][j][1] + b);
        }
    }

    ll ans = 0;
    REP(j,T){
        chmax(ans, DP[N][j][1]);
    }

    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 1000000000;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll dp1[2010][2010];
ll dp2[2010][2010];

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> S(N+1),T(M+1);
    rep(i,N) cin >> S[i];
    rep(i,M) cin >> T[i];
    dp1[0][0] = 1;
    rep(i,N+1) rep(j,M+1){
        dp1[i+1][j] += dp1[i][j];
        dp2[i][j] += dp1[i][j];
        dp2[i][j+1] += dp2[i][j];
        if(S[i] == T[j]){
            dp1[i+1][j+1] += dp2[i][j];
        }
        dp1[i+1][j] %= MOD;
        dp2[i][j] %= MOD;
        dp2[i][j+1] %= MOD;
        dp1[i][j+1] %= MOD;
    }
    cout << dp2[N][M] << endl;
}


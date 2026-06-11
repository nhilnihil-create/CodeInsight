#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<ll>>;
const ll MOD = 998244353;
int main()
{
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    //sort(ALL(A));

    Graph G(N+1);//i個まで選んで和がjになる
    rep(i, N+1)rep(j, S+1){
        G[i].pb(0);
        //if(i==1)if(j == A[i]) G[i][j]++;
    } 
    // rep(i, N)rep(j, S+1)
    // {
    //     if(j == A[i]) G[1][j]++;
    // }
    G[0][0] = 1;
    rep2(i, 0, N)rep(j, S+1) {
       G[i+1][j] += G[i][j]*2;
       if(j>=A[i]) G[i+1][j] +=G[i][j-A[i]] ;
       G[i+1][j]%= MOD;
    }
    // ll ans = 0;
    // rep(i, N+1){
    //     ans += G[i][S];
    //     ans %= MOD;
    // }
    cout << G[N][S]%MOD << endl;




    return 0;
}
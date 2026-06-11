#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 100000000000000
#define N 2100

vector<ll> s(N);
vector<ll> t(N);
vector<vector<ll>> dpsum(N,vector<ll>(N,0));

int main(){
    ll n, m; cin >> n >> m;
    FOR(i,1,n) cin >> s[i];
    FOR(i,1,m) cin >> t[i];
    FOR(i,1,n)FOR(j,1,m){
        if (s[i]==t[j]) dpsum[i][j]=(dpsum[i-1][j]+dpsum[i][j-1]+1)%MOD;
        else dpsum[i][j]=(dpsum[i-1][j]+dpsum[i][j-1]+MOD-dpsum[i-1][j-1])%MOD;
    }
    cout << dpsum[n][m]+1 << endl;
}
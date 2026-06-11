#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ll h, w;    cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));
    vector<vector<ll>> hor(h+1, vector<ll>(w+1, 0)), ver(h+1, vector<ll>(w+1, 0));
    REP(i, h) REP(j, w) cin >> g[i][j];
    REP(i, h){
        REP(j, w){
            if(g[i][j]=='.')    hor[i][j+1] += hor[i][j]+1;
        }
        REPD(j, w)
            if(g[i][j]=='.') hor[i][j] = hor[i][j+1];
    }
    REP(j, w){
        REP(i, h)
            if(g[i][j]=='.')    ver[i+1][j] += ver[i][j]+1;
            
        REPD(i, h)
            if(g[i][j]=='.') ver[i][j] = ver[i+1][j];
    }
    ll res=0;
    REP(i, h+1){
        REP(j, w+1){
            ll tmp = ver[i][j]+hor[i][j];
            if(ver[i][j] && hor[i][j]) tmp -= 1;
            res = max(res, tmp);
        }
    }
    cout << res << endl;

}

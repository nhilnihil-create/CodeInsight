#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))


int main(){
    int h, w;   cin >> h >> w;
    vector<vector<int>> L(h, vector<int>(w, 0)), 
        R(h, vector<int>(w, 0)), D(h, vector<int>(w, 0)), U(h, vector<int>(w, 0)); 

    vector<vector<char>> g(h, vector<char>(w));
    REP(i, h)   REP(j, w)   cin >> g[i][j];

    REP(i, h){
        int tmp=0;
        REP(j, w){
            if(g[i][j]=='#') tmp=0;
            else tmp += 1;
            L[i][j]  = tmp;
        }
        tmp=0;
        REPD(j, w){
            if(g[i][j]=='#') tmp=0;
            else tmp += 1;
            R[i][j]  = tmp;
        }
    }
    REP(j, w){
        int tmp=0;
        REP(i, h){
            if(g[i][j]=='#') tmp=0;
            else tmp += 1;
            D[i][j] = tmp;
        }
        tmp=0;
        REPD(i, h){
            if(g[i][j]=='#') tmp=0;
            else tmp += 1;
            U[i][j] = tmp;
        }
    }
    int ans=0;
    REP(i, h)   REP(j,w) ans = max(ans, L[i][j]+U[i][j]+D[i][j]+R[i][j]-3);
    cout << ans << endl;
}
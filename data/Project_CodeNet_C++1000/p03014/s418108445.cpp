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
        REP(j, w){
            if(g[i][j]=='#') continue;
            
            if(0<j)
                L[i][j] = L[i][j-1]+1;
            else L[i][j] = 1;
        }
        REPD(j, w){
            if(g[i][j]=='#') continue;
            if(j<w-1)
                R[i][j] = R[i][j+1]+1;
            else R[i][j] = 1;
        }
    }
    REP(j, w){
        REP(i, h){
            if(g[i][j]=='#') continue;
            if(0<i)
                D[i][j] = D[i-1][j]+1;
            else D[i][j] = 1;
        }
        REPD(i, h){
            if(g[i][j]=='#') continue;
            if(i<h-1)
                U[i][j] = U[i+1][j]+1;
            else U[i][j] = 1;
        }
    }
    int ans=0;
    REP(i, h)   REP(j,w) ans = max(ans, L[i][j]+U[i][j]+D[i][j]+R[i][j]-3);
    cout << ans << endl;
}
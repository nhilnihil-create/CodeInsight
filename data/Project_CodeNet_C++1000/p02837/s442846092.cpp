#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int g[15][15];

int main() {
    int N;
    cin >> N;

    REP(i, N){
        REP(j, N){
            g[i][j] = -1;
        }
    }

    REP(i, N){
        int m;
        cin >> m;
        REP(j, m){
            int a, x;
            cin >> a >> x;
            --a;
            g[i][a] = x;
        }
    }

    int ans = 0;
    REP(i, 1 << N){
        vector<int> d(N);
        REP(j, N){
            if (i >> j&1){
                d[j] = 1;
            }
        }
        bool ok = true;
        REP(j, N){
            if(d[j]){
                REP(k, N){
                    if(g[j][k] == -1) continue;
                    if(g[j][k] != d[k]) ok = false;
                }
            }
        }
        if (ok) {
            ans = max(ans, __builtin_popcount(i));
        }
    }
    cout << ans << endl;
}
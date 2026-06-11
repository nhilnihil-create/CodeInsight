#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define int long long
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e18 * 5;


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H;
    cin >> H;
    while(H != 0){
        vector< vector<int> > p(7, vector<int>(H));
        REP(i, H) p[0][i] = -1;
        REP(i, H)FOR(j, 1, 6) cin >> p[j][H-1-i];      // 列、行
        REP(i, H) p[6][i] = -1;
        
        int ans = 0;
        int tmp = -1;
        while(tmp != 0){
            tmp = 0;
            REP(i, H){
                int ct = 0, now = 0;
                FOR(j, 1, 7){
                    if(p[now][i] != p[j][i]){
                        if(ct >= 3){
                            tmp += ct*p[now][i];
                            FOR(k, now, j){
                                p[k][i] = -2;
                            }
                        }
                        ct = 1;
                        now = j;
                        
                    }else{
                        ct++;
                    }
                }
            }
            FOR(j, 1, 6){
                p[j].erase(remove(All(p[j]), -2), p[j].end());
                while(p[j].size() != H) p[j].pb(0);
            }
            ans += tmp;
        }
        // REP(i, H){
        //     FOR(j, 1, 6) cout << p[j][H-1-i];
        //     cout << "\n";
        // }
        cout << ans << "\n";
        cin >> H;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF             2e9
#define INF_LL          1LL<<60
#define ll              long long
#define Ceil(x, n)      (((((x))+((n)-1))/n))
#define CeilN(x, n)     (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)    ((x)-(x)%(n))
#define ALL(x)          (x).begin(),(x).end()
typedef pair<int, string>    P;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    reverse(ALL(s));
    
    /* m個1が連続していたら無理 */
    int renzoku = 0;
    REP(i, s.size()) {
        if(s[i] == '1') {
            renzoku++;
            if(renzoku == m) {
                cout << "-1" << endl;
                return 0;
            }
        } else {
            renzoku = 0;
        }
    }

    /* ゴールから見ていく（辞書順最小にしたいので） */
    int now = 0;
    vector<int> ans;
    while(now != n) {
        REP_REV(i, min(n - now, m) + 1) {
            if(s[now + i] == '0') {
                ans.push_back(i);
                now += i;
                break;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    REP(i, ans.size()) {
        cout << ans[i] << " "; 
    }
    cout << endl;
    
    return 0;
}
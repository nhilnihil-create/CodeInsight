#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int64 k;
    cin >> k;
    int32 n = s.size();
    int32 cnt = 0;
    bool flg = true;
    FOR(i,1,n){
        if(s[i-1] != s[i]){
            flg = false;
            break;
        }
    }
    if(flg){
        ANS(k*n/2);
        return 0;
    }
    FOR(i,1,n){
        if(s[i-1] == s[i]){
            ++cnt;
            ++i;
        }
    }
    if(s[0] != s[n-1]){
        ANS(k * cnt);
        return 0;
    }
    int32 a=0,b=0;
    REP(i,n){
        if(s[i] == s[0]){
            ++a;
        }else{
            break;
        }
    }
    FORR(i,n-1,0){
        if(s[i] == s[n-1]){
            ++b;
        }else{
            break;
        }
    }
    ANS(k * cnt - a/2*(k-1) - b/2*(k-1) + (a+b)/2*(k-1));
    return 0;
}

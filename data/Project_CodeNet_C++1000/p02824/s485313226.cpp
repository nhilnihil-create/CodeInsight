#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int64 n,m,v,p;
    cin >> n >> m >> v >> p;
    vector<int64> a(n);
    REP(i,n)cin >> a[i];
    sort(ALL(a),greater<int64>());
    int64 l = p - 1, r = n;
    while(r - l > 1){
        int64 mid = (l + r) / 2;
        bool flg = true;
        if(mid < p){
            flg = true;
        }else if(a[p-1] > a[mid] + m){
            flg = false;
        }else{
            int64 sum = (n - mid) * m + (p - 1) * m;
            FOR(i,p-1,mid){
                sum += min<int64>(m, a[mid] + m - a[i]);
            }
            flg = (sum >= m * v);
        }
        if(flg){
            l = mid;
        }else{
            r = mid;
        }
    }
    ANS(l + 1);
    return 0;
}
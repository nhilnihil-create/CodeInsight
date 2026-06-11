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
    int32 n,k;
    cin >> n >> k;
    vector<int32> a(n);
    int32 sum = 0;
    REP(i,n){
        cin >> a[i];
        sum += a[i];
    }
    vector<int32> div;
    for(int32 x = 1; x * x <= sum; ++x){
        if(sum % x == 0){
            if(x * x == sum){
                div.pb(x);
            }else{
                div.pb(x);
                div.pb(sum / x);
            }
        }
    }
    sort(div.rbegin(), div.rend());
    for(int32 ans : div){
        vector<int32> remain(n);
        REP(i,n){
            remain[i] = (a[i] % ans + ans) % ans;
        }
        sort(ALL(remain));
        vector<int32> psum(n+1,0);
        vector<int32> nsum(n+1,0);
        REP(i,n){
            psum[i+1] = psum[i] + remain[i];
        }
        FORR(i,n-1,0){
            nsum[i] = nsum[i+1] + (ans - remain[i]);
        }
        int32 cnt = INF;
        REP(i,n+1){
            if(psum[i] == nsum[i])cnt = min(cnt,psum[i]);
        }
        // cout << ans << " " << cnt << endl;
        if(cnt > k)continue;
        ANS(ans);
        return 0;
    }
    return 0;
}
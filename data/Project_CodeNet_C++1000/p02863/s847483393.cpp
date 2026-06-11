#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define DEBUG_ARR(v,n) cout<<#v<<":";REP(i,n)cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}

int n,t;
ll dp[3010];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>t;
    vector<pii> ab(n);

    REP(i,n){
        int a,b;
        cin>>a>>b;
        ab[i].first = a;
        ab[i].second = b;
    }
    sort(ALL(ab));

    fill(dp,dp+3010,-1);
    dp[0] = 0;

    REP(i,n){
        FORR(j,0,t){
            if(dp[j]>=0)
                chmax(dp[min(t,j+ab[i].first)], dp[j] + ab[i].second);
        }   
    }

    ll ans = 0;
    FORR(i,0,t+1){;
        if(dp[i]>=0){
            chmax(ans, dp[i]);
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
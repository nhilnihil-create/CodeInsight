#include <bits/stdc++.h>
#define REP(i, n) for(long long i = 0; i < n; i++)
#define REPR(i, n) for(long long i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(long long i = m; i <= n; i++)
#define FORR(i, m, n) for(long long i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;



int main(){FIN
    ll n,t; cin>>n>>t;
    vector<pair<ll,ll>> v;
    REP(i,n){
        ll a,b;cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    VSORT(v);

    vll dp(t, -1e9);
    dp[0]=0;
    ll ans = 0;
    REP(i,n){
        FORR(j,t-1,0){
            if (dp[j]==-1e9) continue;
            if(j+v[i].first < t){
                dp[j+v[i].first] = max(dp[j+v[i].first], dp[j]+v[i].second);
            }
            ans = max(ans, dp[j] + v[i].second);
        }
    }
    cout<<ans<<endl;
    return 0;
}
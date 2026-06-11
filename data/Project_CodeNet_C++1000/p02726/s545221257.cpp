#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}


int main(){FIN
    ll n,x,y;cin>>n>>x>>y;
    x--;
    y--;
    ll dp[n][n];
    REP(i,n)REP(j,n) dp[i][j]=inf;
    REP(i,n) dp[i][i]=0;
    REP(i,n){
        REP(j,n){
            dp[i][j] = min({abs(i-j), abs(i-x)+abs(j-y)+1, abs(i-y)+abs(j-x)+1});

        }
    }
    map<ll,ll> mp;
    REP(i,n){
        REP(j,n){
            mp[dp[i][j]]++;
        }
    }
    FOR(i,1,n-1){
        cout<<mp[i]/2<<endl;
    }
    return 0;
}

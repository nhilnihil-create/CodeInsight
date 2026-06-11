#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define repm(i,a,b) for(ll i=(ll)(a);i>(ll)(b);i--)
#define all(v) v.begin(), v.end()
#define rall(x) (x).rbegin(),(x).rend()
#define pll pair<long long,long long>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define vc vector<char>
#define vvc vector<vc>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vb =vector<bool>;
using vvb=vector<vb>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//snippets:tmp,cl,cvl,cs,co,coy,con,cov,setp

int main(){
    const ll mod=998244353;
    ll n;
    cin >> n;
    ll s;
    cin >> s;
    vll a(n);
    rep(i, n) cin >> a[i];
    vvll dp(n,vll(s+1,0));
    if(a[0]<s+1)dp[0][a[0]]=1;
    dp[0][0]=2;
    repi(i,1,n){
        rep(j,s+1){
            dp[i][j]+=dp[i-1][j]*2;
            dp[i][j]%=mod;
            if(j+a[i]<s+1){
                dp[i][j+a[i]]+=dp[i-1][j];
                dp[i][j+a[i]]%=mod;
            }
        }
    }
    cout << dp[n-1][s]%mod << endl;
}
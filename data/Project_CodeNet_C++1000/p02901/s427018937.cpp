#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue;
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> vec){ return (ll)vec.size(); }
ll sz(string s){ return (ll)s.size(); }

ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }

int main(){
    ll n,m;
    cin >> n >> m;
    ll a[m] = {};
    ll memo[m] = {};
    
    rep(i,0,m){
        ll b;
        cin >> a[i] >> b;
        rep(j,0,b){
            ll c;
            cin >> c;
            memo[i] |= (1 << (c-1)); 
        }
    }

    vector<ll> dp((ll)pow(2,n),LINF);
    dp[0] = 0;
    rep(i,0,(ll)pow(2,n)){
        rep(j,0,m){
            dp[i | memo[j]] = min(dp[i | memo[j]],dp[i] + a[j]);
        }
    }

    if(dp[(ll)pow(2,n)-1] == LINF) cout << -1 << endl;
    else cout << dp[(ll)pow(2,n)-1] << endl;

    return 0;
}



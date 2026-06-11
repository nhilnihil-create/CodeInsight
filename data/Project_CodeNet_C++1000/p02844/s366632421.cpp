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


int main(){
    ll n;
    cin >> n;
    ll dp[3][10] = {};
    string s;
    cin >> s;
    rep(k,0,s.size()){
        ll i = s.size()-k-1;
        ll temp = 0,temp2 = 0;
        rep(j,0,10){
            temp += dp[0][j];
            temp2 += dp[1][j];
        }
        dp[0][s[i] - '0'] = 1;
        if(k > 0) dp[1][s[i] - '0'] = temp;
        if(k > 1) dp[2][s[i] - '0'] = temp2;
    }

    ll ans = 0;
    rep(i,0,10) ans += dp[2][i];
    cout << ans << endl;

    return 0;
}

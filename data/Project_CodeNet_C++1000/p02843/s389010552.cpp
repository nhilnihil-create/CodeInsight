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
    
    ll x;
    cin >> x;
    ll dp[x+1] = {};
    dp[0] = 1;
    rep(i,100,x+1){
        rep(j,0,6){
            if(i >= 100+j) dp[i] = max(dp[i],dp[i-100-j]);
        }
    }
    cout << dp[x] << endl;

    return 0;
}
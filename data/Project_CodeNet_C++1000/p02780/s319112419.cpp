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

#include <bits/stdc++.h>
#define rep(i,a,n) for(ll i = a;i < n;i++)
typedef long long ll;
using namespace std;

int main(){
    
    ll n,k;
    cin >> n >> k;
    double ruiseki[n] = {};

    rep(i,0,n){
        ll a;
        cin >> a;
        ruiseki[i] = (double)(1+a)/2.0;
        if(i > 0) ruiseki[i] += ruiseki[i-1];
    }

    double ans = 0;
    rep(i,k-1,n){
        if(i == k-1) ans = ruiseki[i];
        else ans = max(ans,ruiseki[i] - ruiseki[i-k]);
    }
    cout << setprecision(10) << ans << endl;
    return 0;
}

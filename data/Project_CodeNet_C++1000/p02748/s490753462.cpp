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
    ll A,B,M;
    cin >> A >> B >> M;
    ll a[A],b[B],x[M],y[M],c[M];
    
    ll ans = 0,memo = LINF;
    rep(i,0,A){
        cin >> a[i];
        memo = min(memo,a[i]);
    }
    ans += memo;
    rep(i,0,B){
        cin >> b[i];
        memo = min(memo,b[i]);
    }
    ans += memo;

    rep(i,0,M){
        cin >> x[i] >> y[i] >> c[i];
        ans = min(ans,a[x[i]-1]+b[y[i]-1]-c[i]);
    }
    cout << ans << endl;

    return 0;
}
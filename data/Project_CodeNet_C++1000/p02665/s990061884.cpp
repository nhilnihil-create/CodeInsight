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

int main(){
    ll n;
    cin >> n;
    n++;
    ll a[n] = {};
    rep(i,0,n){
        cin >> a[i];
    }

    P cnt[n] = {};
    cnt[n-1] = P(a[n-1],a[n-1]);
    rep(k,1,n){
        ll i = n-k-1;
        cnt[i].fs = cnt[i+1].fs/2 + cnt[i+1].fs%2 + a[i];
        cnt[i].sc = cnt[i+1].sc + a[i];
    }
    if(cnt[0].fs > 1){
        cout << -1 << endl;
        return 0;
    }
    
    ll memo = 1,ans = 0;
    rep(i,0,n){
        memo = min(cnt[i].sc,memo);
        ans += memo;
        memo -= a[i];
        memo *= 2;
    }
    cout << ans << endl;
    return 0;
}



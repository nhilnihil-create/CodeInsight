#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 100000000000000

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n); ll atot = 0;
    REP(i,n) cin >> a[i];
    REP(i,n) atot+=a[i];
    vector<ll> divl;
    FOR(i,1,23000){
        if (atot%i==0&&i<=atot/i){
            divl.pb(i);
            divl.pb(atot/i);
        }
    }
    sort(divl.begin(),divl.end());
    ll ans = 1;
    REP(j,divl.size()){
        vector<ll> b(n);
        REP(i,n) b[i]=a[i]%divl[j];
        sort(b.begin(),b.end());
        FOR(i,1,n-1) b[i]=b[i]+b[i-1];
        bool jud = false;
        FOR(i,0,n-2){
            ll z = max(b[i],(n-i-1)*divl[j]-b[n-1]+b[i]);
            if (z<=k) jud = true;
        }
        if (jud) ans = max(ans,divl[j]);
    }
    cout << ans << endl;
}
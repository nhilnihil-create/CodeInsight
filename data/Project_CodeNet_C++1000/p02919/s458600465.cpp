#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define exists(s,x) (s).find(x)!=(s).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)
#define fi first
#define se second
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

inline ll add(ll x, ll y) {return (x+y)%MOD;}
inline ll mul(ll x, ll y) {return (x*y)%MOD;}
inline ll sub(ll x, ll y) {
    ll res = x - y;
    if(res < 0) res += MOD;
    return res;
}
inline ll modpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y&1) res = mul(res,x);
        y >>= 1;
        x = mul(x,x);
    }
    return res;
}

int main(){
    int N; cin >> N;
    vector<int> P(N);
    vector<int> IP(N);
    REP(i,N) {
        cin >> P[i]; P[i] --;
        IP[P[i]] = i;
    }
    multiset<int> S;
    S.insert(-1);
    S.insert(-1);
    S.insert(N);
    S.insert(N);
    ll ans = 0;
    for(int i=N-1; i>=0; --i) {
        auto it = S.lower_bound(IP[i]);
        int r1 = *it;
        it++;
        int r2 = *it;
        it--;it--;
        int l1 = *it;
        it--;
        int l2 = *it;
        //cout << l2 << " " << l1 << " " << IP[i] << " " << r1 << " " << r2 << endl;
        ll tmp = 0;
        tmp += (ll)(r1-IP[i]) * (l1-l2); 
        tmp += (ll)(r2-r1) * (IP[i]-l1);
        ans += tmp * (i+1);
        S.insert(IP[i]);
    }
    cout << ans << endl;
    return 0;
}
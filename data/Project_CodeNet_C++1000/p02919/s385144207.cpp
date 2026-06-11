#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    int p[n];
    ll pos[n + 1];
    REP(i,n){
        cin >> p[i];
        pos[p[i]] = i;
    }
    multiset<ll> s;
    s.insert(-1);
    s.insert(-1);
    s.insert(n);
    s.insert(n);
    s.insert(pos[n]);
    ll ans = 0;
    for(ll i = n - 1; i >= 1; i--){
        auto itr = s.upper_bound(pos[i]);
        ll r1 = *itr;
        itr++;
        ll r2 = *itr;
        for(int j = 0; j < 2; j++) itr--;
        ll l1 = *itr;
        itr--;
        ll l2 = *itr;
        ans += i * ((r2 - r1) * (pos[i] - l1) + (l1 - l2) * (r1 - pos[i]));
        s.insert(pos[i]);
    }
    cout << ans << endl;
    return 0;
}
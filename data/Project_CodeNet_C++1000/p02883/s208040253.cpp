#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n), f(n);
    rep(i, n)cin >> a[i];
    rep(i, n)cin >> f[i];

    sort(ALL(a));
    sort(ALL(f), greater<ll>());

    ll left = 0;
    ll right = a.back()*f.front();
    while(left < right){
        ll mid = left + (right - left) / 2;

        ll cnt = 0;
        rep(i, n){
            ll x = mid / f[i];

            cnt += max(0LL, a[i]-x);
        }

        if(cnt <= k)right = mid;
        else left = mid+1;
    }

    cout << right << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(long long i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;


int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    priority_queue<ll> fac;
    for (ll i=1; i*i<=sum; i++) {
        if (sum%i==0) {
            fac.push(i);
            if (i*i!=sum) {
                fac.push(sum/i);
            }
        }
    }

    bool ok = false;
    while (!fac.empty() && !ok) {
        ll now = fac.top();
        fac.pop();
        ll num = 0;
        vector<ll> r(n);
        rep(i, n) r[i] = a[i] % now;
        sort(r.begin(), r.end());
        vector<ll> v1(n);
        vector<ll> v2(n);
        rep(i, n) {
            if (i==0) {
                v1[i] = r[i];
                v2[n-1-i] = now - r[n-1-i];
            }
            else {
                v1[i] = v1[i-1] +r[i];
                v2[n-1-i] = v2[n-i] + now - r[n-1-i];
            }
            
        }
        ll res = 0;
        ll yy = v1[n-1]/now;
        res = v1[n-1-yy];
        /*
        rep(i, n-1) {
            if (v1[i]==v2[i+1]) {
                res = v1[i];
                break;
            }
        }
        */
        if (res<=k) {
            ok = true;
            cout << now << endl;
            return 0;
        }
    }

    
    return 0;
}

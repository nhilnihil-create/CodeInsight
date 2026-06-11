#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    vector<int> c(n);
    rep(i,n) {
        int px;
        cin >> px;
        p[i] = px-1;
    }
    rep(i,n) cin >> c[i];

    
    ll ans = LLONG_MIN;
    rep(sp,n) {
        int pos = sp;
        vector<int> v;
        ll tot = 0;
        while (1) {
            pos = p[pos];
            v.push_back(c[pos]);
            tot += c[pos];
            if (pos == sp) break;
        }   

        int l = v.size();
        ll cum = 0;
        rep(i,l) {
            cum += v[i];
            if (i+1 > k) break;
            ll t = cum;
            if (tot > 0) {
                ll e = (k-i-1)/l;
                t += tot*e;
            }
            ans = max(t, ans);
        }
    }

    cout << ans << endl;
    return 0;
}
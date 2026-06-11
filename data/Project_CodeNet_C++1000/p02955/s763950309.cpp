#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

vector<int> divisor(int N) {
    vector<int> RES;
    for (int I = 1; I*I <= N; I++) {
        if (N%I == 0) {
            RES.push_back(I);
            if (I != N/I) RES.push_back(N/I);
        }
    }
    return RES;
}

int main() {
    int n; cin >> n;
    ll k; cin >> k;
    int a[n]; rep(i,n) cin >> a[i];

    int s = 0;
    rep(i,n) s += a[i];
    vector<int> d = divisor(s);

    int ans = 1;

    for (auto g : d) {
        vector<int> r;
        rep(i,n) r.push_back(a[i]%g);
        sort(r.begin(),r.end());

        int sum_r = 0; rep(i,n) sum_r += r[i];
        int cmax = sum_r / g;
        int c = 0;
        rep(i,n-cmax) c += r[i];
        if ((ll)c <= k) ans = max(g,ans);
    }

    cout << ans << endl;
    return 0;
}
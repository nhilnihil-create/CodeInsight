#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

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
    sort(d.begin(), d.end());

    int ans = 1;

    for (auto di : d) {
        vector<int> b;
        rep(i,n) b.push_back(a[i]%di);
        sort(b.begin(),b.end());
        int s = 0;
        rep(i,n) s += b[i];
        int cmax = s / di;
        int c = 0;
        rep(i,n-cmax) c += b[i];
        if ((ll)c <= k) ans = di;

        //rep(i,n-1) printf("%d ",b[i]);
        //printf("%d\n",b[n-1]);
    }

    cout << ans << endl;
    return 0;
}

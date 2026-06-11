#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9;

double expectation(int num) {
    int sum = 0;
    for (int i=1; i<=num; ++i) sum += i;
    return (double) sum / (double) num;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    vector<int> p(n);
    rep (i, n) cin >> p[i];
    vector<int> s(n, 0);
    rep (i, n) s[i+1] = s[i] + p[i]; 
    int m = -INF;
    int pos = -1;
    rep (i, n-k+1) {
        int v = s[k+i]-s[i];
        if (m < v) {
            m = v;
            pos = i;
        }
    }
    double ans=0;
    for (int i=pos; i < pos + k; ++i) {
        ans += expectation(p[i]);
    }
    cout << fixed;
    cout << setprecision(7) << ans << endl;
    return 0;
}
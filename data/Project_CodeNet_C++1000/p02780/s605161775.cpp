#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    int n, k;
    cin >> n >> k;
    double ans;
    vector<int>p(n);
    rep(i, n) cin >> p[i];
    int psum = 0;
    int pa;
    rep(i, k) psum += p[i] + 1;
    pa = psum;
    for (int i = 0; i + k < n; i++) {
        psum = psum - p[i] + p[i + k];
        if (pa < psum) {
            pa = psum;
        }
    }
    cout << fixed << setprecision(15) << (double)pa*0.5 << endl;
    
    return 0;
}

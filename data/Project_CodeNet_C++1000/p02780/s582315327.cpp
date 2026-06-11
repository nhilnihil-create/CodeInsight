#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int n, k;
    cin >> n >> k;
    
    vector<double> p(n);
    rep(i,n) {
        cin >> p[i];
    }
    
    rep(i,n) {
        p[i] = (p[i] - 1) / 2 + 1;
    }
    
    vector<double> sum(n-k+1);
    rep(i,k) {
        sum[0] += p[i];
    }
    
    double mx = sum[0];
    for(int i = 1; i < n-k+1; i++) {
        sum[i] = sum[i-1] + p[i+k-1] - p[i-1];
        mx = max(mx, sum[i]);
    }
    
    cout << fixed << setprecision(7) << mx << endl;
    
    
    return 0;
}

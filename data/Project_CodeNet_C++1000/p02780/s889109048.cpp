#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<double> p(n);
    rep(i,n) {
        double x;
        cin >> x;
        p[i] = (1+x)/2;
    }
    double sumk = 0;
    for (int i = 0; i <= k-1; i++) {
        sumk += p[i];
    }
    double ans = sumk;
    for (int i = 1; i <= n-k; i++) {
        sumk = sumk-p[i-1]+p[i+k-1];
        ans = max(ans, sumk);
    }
    printf("%.10f\n", ans);
    return 0;
}
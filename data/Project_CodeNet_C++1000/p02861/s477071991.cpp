#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<P> a(n);
    rep(i,n) {
        int x, y;
        cin >> x >> y;
        a[i] = P(x,y);
    }
    double sum = 0;
    int cnt = 0;
    vector<int> p(n);
    rep(i,n) p[i] = i;
    do {
        cnt++;
        rep(i,n-1) {
            double x = a[p[i]].first - a[p[i+1]].first;
            double y = a[p[i]].second - a[p[i+1]].second;
            double d = sqrt(x*x + y*y);
            sum += d;
        }
    } while (next_permutation(p.begin(), p.end()));
    double ans = sum/cnt;
    printf("%.10f\n", ans);
    return 0;
}
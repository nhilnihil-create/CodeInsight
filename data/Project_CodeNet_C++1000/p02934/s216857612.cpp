#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main() {
    ll n;
    cin >> n;
    double ans;
    rep(i,n) {
        double t;
        cin >> t;
        ans += 1/t;
    }
    printf("%.15f\n", 1/ans);
    return 0;
}

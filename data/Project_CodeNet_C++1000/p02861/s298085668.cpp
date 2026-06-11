#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
typedef long long ll;

int factorial(int n) {
    if (n <= 1) return 1;
    else return n * factorial(n-1);
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int x[n], y[n];
    rep (i, n) cin >> x[i] >> y[i];
    int fact = factorial(n);
    double res = 0;
    rep (i, n-1) {
        Rep (j, i+1, n) {
            res += sqrt(pow(x[j]-x[i],2)+pow(y[j]-y[i],2))*2*factorial(n-1);
        }
    }
    printf("%.10f", res/fact);
}
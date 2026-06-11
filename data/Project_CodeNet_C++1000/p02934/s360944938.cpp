#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    double a[n];
    double sum = 0;
    rep (i, n) {
        cin >> a[i];
        sum += 1/a[i];
    }
    printf("%f", 1/sum);
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    double pi[n];
    double ans = 0.0, ansm;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &pi[i]);
    }
    for (int i = 0; i < k; i++) {
        ans += (pi[i] + 1.0) / 2.0;
    }
    ansm = ans;
    if (n > 1) {
        for (int i = 0; i + k < n; i++) {
            ans += -((pi[i] + 1.0) / 2.0) + ((pi[k+i] + 1.0) / 2.0);
            ansm = max(ansm, ans);
        }
    }
    printf("%13.12lf\n", ansm);
}
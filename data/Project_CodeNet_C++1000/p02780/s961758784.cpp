#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; scanf("%d%d", &n, &k);
    double sum = 0, ret = 0;
    vector<double> p(n);
    for (int i = 0; i < k-1; i++) {
        scanf("%lf", &p[i]);
        p[i] = (1+p[i])/2;
        sum += p[i];
    }
    for (int i = k-1; i < n; i++) {
        scanf("%lf", &p[i]);
        p[i] = (1+p[i])/2;
        sum += p[i];
        ret = max(ret, sum);
        sum -= p[i-k+1];
    }
    printf("%1.10lf\n", ret);
    return 0;
}
#include <cstdio>
#include <cmath>

int main() {
    while (1) {
        int s[1000] = {};
        int n, sum = 0;
        double m, a2 = 0.0;
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
            sum += s[i];
        }
        m = (double)sum / n;
        for (int i = 0; i < n; i++) {
            a2 += pow((s[i] - m), 2);
        }
        a2 /= n;
        a2 = sqrt(a2);
        printf("%f\n", a2);
    }
    return 0;
}

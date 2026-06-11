#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double d;
    scanf("%d %lf", &n, &d);
    int sum= 0;
    for (int i= 0;i< n;i++) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        double dis= sqrt(x* x+ y* y);
        if (dis <= d) sum++;
    }
    cout << sum << endl;
}
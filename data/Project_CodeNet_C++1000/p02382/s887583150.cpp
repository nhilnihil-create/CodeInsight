#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
using namespace std;

int main() {
    int n, i;
    double x[101], y[101], sum = 0, max = 0;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    for (i = 0; i < n; i++) {
        sum += fabs(x[i] - y[i]);
    }
    printf("%lf\n", sum);
    sum = 0;

    for (i = 0; i < n; i++) {
        sum += pow(fabs(x[i] - y[i]), 2.0);
    }
    printf("%lf\n", sqrt(sum));
    sum = 0;

    for (i = 0; i < n; i++) {
        sum += pow(fabs(x[i] - y[i]), 3.0);
    }
    printf("%lf\n", pow(sum, 1.0 / 3.0));
    sum = 0;

    for (i = 0; i < n; i++) {
        if (fabs(x[i] - y[i]) > max) max = fabs(x[i] - y[i]);
    }
    printf("%lf\n", max);

    return 0;
}
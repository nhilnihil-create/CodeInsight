#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    double ans = 0, t;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &t);
        ans += (1/t);
    }
    printf("%.6lf\n", (1/ans));
    return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;
double arr[50];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%lf", &arr[i]);
    double res;
    sort(arr, arr+N);
    res = arr[0];
    for (int i = 1; i < N; i++) {
        res = (res + arr[i]) / 2;
    }
    printf("%.6lf\n", res);
    return 0;
}

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int size;
    scanf("%d", &size);
    vector<int> a, b;
    for (int i = 0; i < size; i++) {
        int tmp;
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    for (int i = 0; i < size; i++) {
        int tmp;
        scanf("%d", &tmp);
        b.push_back(tmp);
    }
    double sum = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > b[i]) {
            sum += a[i] - b[i];
        } else {
            sum -= a[i] - b[i];
        }
    }
    printf("%f\n", sum);
    sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    printf("%f\n", sqrt(sum));
    sum = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > b[i]) {
            sum += (a[i] - b[i]) * (a[i] - b[i]) * (a[i] - b[i]);
        } else {
            sum -= (a[i] - b[i]) * (a[i] - b[i]) * (a[i] - b[i]);
        }
    }
    printf("%f\n", pow(sum, 1.0 / 3.0));
    double max = 0;
    for (int i = 0; i < size; i++) {
        if (max < a[i] - b[i] || max < b[i] - a[i]) {
            max = fabs(a[i] - b[i]);
        }
    }
    printf("%f\n", max);
}
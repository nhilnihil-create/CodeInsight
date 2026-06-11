#include <stdio.h>
#include <stdlib.h>

#define LL long long int

typedef struct {
    int index;
    LL value;
} tValueLL;

int cmpLL(const void *n1, const void *n2) {

    if (((tValueLL *)n1)->value > ((tValueLL *)n2)->value) {
        return 1;
    } else if (((tValueLL *)n1)->value < ((tValueLL *)n2)->value) {
        return -1;
    }

    return 0;
}


int main(void) {

    int n;
    scanf("%d", &n);
    tValueLL *a = (tValueLL *)malloc(n * sizeof(tValueLL));
    tValueLL *b = (tValueLL *)malloc(n * sizeof(tValueLL));
    for (int i = 0; i < n; i ++) {
        a[i].index = i;
        b[i].index = i;
        scanf("%lld %lld", &a[i].value, &b[i].value);
    }

    qsort(a, n, sizeof(tValueLL), cmpLL);
    qsort(b, n, sizeof(tValueLL), cmpLL);

    int ret;
    if (n % 2 == 1) {
        ret = b[(n - 1) / 2].value - a[(n - 1) / 2].value + 1;
    } else {
        ret = (b[n / 2 - 1].value + b[n / 2].value) - (a[n / 2 - 1].value + a[n / 2].value) + 1;
    }

    printf("%d", ret);

    return 0;
}

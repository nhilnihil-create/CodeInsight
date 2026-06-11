#include <stdio.h>
int main()
{
    long sum;
    int min, max, a[10000], n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);// can do that!?
        if (i == 0) {
            max = a[i];
            min = a[i];
        }
        else if (a[i] > max) {
            max = a[i];
        }
        else if (a[i] < min) {
            min = a[i];
        }
        sum += a[i];
    }
    printf("%d %d %ld\n", min, max, sum);
    return 0;
}
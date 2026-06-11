#include <stdio.h>
#include<math.h>

int main()
{
    double n, x, t, ans, r;
    scanf("%lf%lf%lf", &n, &x, &t);

    ans = (n*t)/x;
    r = ceil(ans/t);
    printf("%.0lf\n", r*t);
    return 0;
}

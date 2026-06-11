#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    int ans = B + C - A >= 0 ? B + C - A : 0;
    printf("%d\n", ans);
    return 0;
}

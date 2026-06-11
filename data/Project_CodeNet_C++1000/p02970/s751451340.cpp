#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n, d; scanf("%d %d", &n, &d);

    if (n % (2*d + 1) == 0) printf("%d\n", n / (2*d + 1));
    else                    printf("%d\n", n / (2*d + 1) + 1);
}
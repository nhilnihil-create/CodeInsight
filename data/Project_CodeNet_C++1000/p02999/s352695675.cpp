#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int X, A;
    scanf("%d%d", &X, &A);
    int ans = X < A ? 0 : 10;
    printf("%d\n", ans);
    return 0;
}

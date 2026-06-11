#include <cstdio>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);
    printf("%d\n", N % 2 == 0 ? N / 2 - 1 : N / 2);
}

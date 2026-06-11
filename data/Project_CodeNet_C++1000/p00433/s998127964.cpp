#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int a, b;
    int i;

    a = b = 0;
    for (i = 0; i < 8; i++){
        scanf("%d", &n);

        if (i < 4){
            a += n;
        }
        else {
            b += n;
        }
    }
    printf("%d\n", max(a, b));

    return (0);
}